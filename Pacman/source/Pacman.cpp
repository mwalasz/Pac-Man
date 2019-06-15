#include "Pacman.h"

Pacman::Pacman() : isFrightening(false), killedGhosts(0)
{
	if (!texture.loadFromFile(SPRITE_SHEETS_PATH + PACMAN_SPRITESHEET)
		|| !deadTexture.loadFromFile(SPRITE_SHEETS_PATH + DEAD_PACMAN_SPRITESHEET))
		throw NoTextureLoadedException();
	else
	{
		this->Set_MovementSpeed(PACMAN_SPEED_INIT);
		this->Set_Direction(Character::Directions::Right);

		sprite.setTexture(this->texture);
		sprite.setTextureRect(sf::IntRect(0, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
		sprite.setPosition(PACMAN_X, PACMAN_Y);
	}
}

Pacman::~Pacman()
{
}

void Pacman::Move(bool isCollision)
{
	int multiplier = 0;

	if(counterWalking == 5)
		multiplier = 2;

	Character::SetDirectionFromKeyboardInput();

	Character::Directions tempDirection = this->Get_Direction();

	if (tempDirection == Character::Directions::Up)
	{
		if (this->Get_CanMoveUp())
		{
			this->sprite.move(0, this->Get_MovementSpeed() * -1);
			this->sprite.setTextureRect(sf::IntRect((multiplier + 1) * GRAPHIC_SIZE, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
			this->Set_AllCanMoveParameters(true);
		}
	}
	else if (tempDirection == Character::Directions::Down)
	{
		if (this->Get_CanMoveDown())
		{
			this->sprite.move(0, this->Get_MovementSpeed());
			this->sprite.setTextureRect(sf::IntRect((multiplier + 5) * GRAPHIC_SIZE, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
			this->Set_AllCanMoveParameters(true);
		}
	}
	else if (tempDirection == Character::Directions::Left)
	{
		if (this->Get_CanMoveLeft())
		{
			this->sprite.move(this->Get_MovementSpeed() * -1, 0);
			this->sprite.setTextureRect(sf::IntRect(multiplier * GRAPHIC_SIZE, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
			this->Set_AllCanMoveParameters(true);
		}

	}
	else if (tempDirection == Character::Directions::Right)
	{
		if (this->Get_CanMoveRight())
		{
			this->sprite.move(this->Get_MovementSpeed(), 0);
			this->sprite.setTextureRect(sf::IntRect((multiplier + 4) * GRAPHIC_SIZE, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
			this->Set_AllCanMoveParameters(true);
		}
	}

	this->TeleportBetweenExits();

	counterWalking++;

	if(counterWalking == 6)
	{
		counterWalking = 0;
		multiplier = 0;
	}
}

void Pacman::TeleportBetweenExits()
{
	if ((this->sprite.getPosition().x >= X_LEFT_ENTRY_POINT_SIDE_EXITS &&
		this->sprite.getPosition().x <= X_LEFT_ENTRY_POINT_SIDE_EXITS + 1) &&
		(this->sprite.getPosition().y >= Y_TOP_ENTRY_POINT_SIDE_EXITS &&
			this->sprite.getPosition().y <= Y_BOTTOM_ENTRY_POINT_SIDE_EXITS))
		this->sprite.setPosition(X_RIGHT_ENTRY_POINT_SIDE_EXITS - 1, this->sprite.getPosition().y); //transfer pacman from left to right
	else if ((this->sprite.getPosition().x >= X_RIGHT_ENTRY_POINT_SIDE_EXITS &&
		this->sprite.getPosition().x <= X_RIGHT_ENTRY_POINT_SIDE_EXITS + 1) &&
		(this->sprite.getPosition().y >= Y_TOP_ENTRY_POINT_SIDE_EXITS &&
			this->sprite.getPosition().y <= Y_BOTTOM_ENTRY_POINT_SIDE_EXITS))
		this->sprite.setPosition(X_LEFT_ENTRY_POINT_SIDE_EXITS + 1, this->sprite.getPosition().y); //transfer pacman from right to left
}

bool Pacman::DotCollision(std::vector<Dot> & dots, Player & player)
{
	std::vector<Dot>::const_iterator iter;

	for (iter = dots.begin(); iter!= dots.end(); iter++)
	{ 
		if (this->sprite.getGlobalBounds().intersects((*iter).circle.getGlobalBounds()))
		{
			if ((*iter).isSuperDot)
				isFrightening = true;

			player.results.AddPointsToTotalScore((*iter));
			dots.erase(iter);
			return true;
		}
	}
	
	return false;
}

bool Pacman::GhostCollision(std::vector<Ghost*> ghosts, Player& player)
{
	for (auto a : ghosts)
	{
		if (this->sprite.getGlobalBounds().intersects(a->Get_Sprite().getGlobalBounds()))
		{
			if (isFrightening) //Pacman kills
			{
				this->killedGhosts++;
				a->KilledRightNow(player, this->killedGhosts);
			}
			return true;
		}
		else continue;
	}

	return false;
}

void Pacman::Set_IsFrightening(bool toSet)
{
	this->isFrightening = toSet;
}

bool Pacman::Get_IsFrightening()
{
	return this->isFrightening;
}

void Pacman::DeadAnimation(sf::RenderWindow& window)
{
	this->sprite.setTexture(deadTexture);

	int i = 0;
	while (i < 12)
	{
		this->sprite.setTextureRect(sf::IntRect(i, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
		window.draw(this->sprite);
		window.display();
		_sleep(1000);
		i++;
	}

	this->sprite.setTexture(this->texture);
}

void Pacman::Set_KilledGhosts(int toSet)
{
	this->killedGhosts = toSet;
}

int Pacman::Get_KilledGhosts()
{
	return this->killedGhosts;
}
