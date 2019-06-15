#include "InkyBlueGhost.h"

InkyBlueGhost::InkyBlueGhost()
{
	if (!texture.loadFromFile(SPRITE_SHEETS_PATH + BLUE_GHOST_SPRITESHEET))
		throw NoTextureLoadedException();
	else
	{
		this->normalMovementSpeed = BLUE_GHOST_SPEED_INIT;
		this->slowMovementSpeed = BLUE_GHOST_SPEED_SCARED;

		this->Set_Direction(Character::Directions::Down);
		this->Set_MovementSpeed(BLUE_GHOST_SPEED_INIT);
		sprite.setTexture(this->texture);
		sprite.setTextureRect(sf::IntRect(0, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
		sprite.setPosition(BLUE_GHOST_X_INIT, BLUE_GHOST_Y_INIT);
	}
}

InkyBlueGhost::~InkyBlueGhost()
{
}

void InkyBlueGhost::KilledRightNow(Player& player, int howManyKilled)
{
	Set_IsAlive(false);
	Set_IsVisible(false);
	this->Set_Position(BLUE_GHOST_X, BLUE_GHOST_Y);
	player.results.AddPointsToTotalScore(this->Ghost::HowManyPointsAddForKillingManyGhost(howManyKilled));
}

void InkyBlueGhost::Move(bool isCollision, Pacman pacman)
{
	Character::Directions currentDirection = this->Get_Direction();

	if (isAlive)
	{
		if (currentDirection == Character::Directions::Up)
		{
			if (this->Get_CanMoveUp())
			{
				this->sprite.move(0, this->Get_MovementSpeed() * -1);
				this->sprite.setTextureRect(sf::IntRect(6 * GRAPHIC_SIZE, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
				this->Set_AllCanMoveParameters(true);
			}
			else if (isCollision)
				this->Set_Direction(GetRandomDirection(currentDirection));
		}
		else if (currentDirection == Character::Directions::Down)
		{
			if (this->Get_CanMoveDown())
			{
				this->sprite.move(0, this->Get_MovementSpeed());
				this->sprite.setTextureRect(sf::IntRect(2 * GRAPHIC_SIZE, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
				this->Set_AllCanMoveParameters(true);
			}
			else if (isCollision)
				this->Set_Direction(GetRandomDirection(currentDirection));
		}
		else if (currentDirection == Character::Directions::Left)
		{
			if (this->Get_CanMoveLeft())
			{
				this->sprite.move(this->Get_MovementSpeed() * -1, 0);
				this->sprite.setTextureRect(sf::IntRect(4 * GRAPHIC_SIZE, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
				this->Set_AllCanMoveParameters(true);
			}
			else if (isCollision)
				this->Set_Direction(GetRandomDirection(currentDirection));
		}
		else if (currentDirection == Character::Directions::Right)
		{
			if (this->Get_CanMoveRight())
			{
				this->sprite.move(this->Get_MovementSpeed(), 0);
				this->sprite.setTextureRect(sf::IntRect(0 * GRAPHIC_SIZE, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
				this->Set_AllCanMoveParameters(true);
			}
			else if (isCollision)
				this->Set_Direction(GetRandomDirection(currentDirection));
		}
	}
}