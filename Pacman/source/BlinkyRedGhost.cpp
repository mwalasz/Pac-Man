#include "BlinkyRedGhost.h"

BlinkyRedGhost::BlinkyRedGhost()
{
	if(!texture.loadFromFile(SPRITE_SHEETS_PATH + RED_GHOST_SPRITESHEET))
		throw NoTextureLoadedException();
	else
	{
		this->normalMovementSpeed = RED_GHOST_SPEED_INIT;
		this->slowMovementSpeed = RED_GHOST_SPEED_SCARED;

		this->Set_Direction(Character::Directions::Up);
		this->Set_MovementSpeed(RED_GHOST_SPEED_INIT);
		sprite.setTexture(this->texture);
		sprite.setTextureRect(sf::IntRect(0, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
		sprite.setPosition(RED_GHOST_X_INIT, RED_GHOST_Y_INIT);
	}
}

BlinkyRedGhost::~BlinkyRedGhost()
{
}

void BlinkyRedGhost::KilledRightNow(Player& player, int howManyKilled)
{
	Set_IsAlive(false);
	Set_IsVisible(false);
	this->Set_Position(RED_GHOST_X, RED_GHOST_Y);
	player.results.AddPointsToTotalScore(this->Ghost::HowManyPointsAddForKillingManyGhost(howManyKilled));
}

void BlinkyRedGhost::Move(bool isCollision, Pacman pacman)
{
	Character::Directions currentDirection = this->Get_Direction();

	Character::Directions nextDirection = CalculateNextMoveForFollowing(pacman, isCollision);

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
				this->Set_Direction(CalculateNextMoveForFollowing(pacman, isCollision));
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
				this->Set_Direction(CalculateNextMoveForFollowing(pacman, isCollision));
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
				this->Set_Direction(CalculateNextMoveForFollowing(pacman, isCollision));
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
				this->Set_Direction(CalculateNextMoveForFollowing(pacman, isCollision));
		}
	}
}