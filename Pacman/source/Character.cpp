#include "Character.h"
#include <random>

Character::Character() : canMoveUp(true), canMoveDown(true), canMoveRight(true),
canMoveLeft(true), direction(Character::Directions::Right), movementSpeed(0.0f) {}

Character::~Character()
{
}

#pragma region Setters

void Character::Set_CanMoveUp(bool toSet)
{
	this->canMoveUp = toSet;
}

void Character::Set_CanMoveDown(bool toSet)
{
	this->canMoveDown = toSet;
}

void Character::Set_CanMoveRight(bool toSet)
{
	this->canMoveRight = toSet;
}

void Character::Set_CanMoveLeft(bool toSet)
{
	this->canMoveLeft = toSet;
}

void Character::Set_AllCanMoveParameters(bool toSet)
{
	this->Set_CanMoveUp(toSet);
	this->Set_CanMoveDown(toSet);
	this->Set_CanMoveRight(toSet);
	this->Set_CanMoveLeft(toSet);
}

void Character::Set_Direction(Directions toSet)
{
	this->direction = toSet;
}

void Character::Set_MovementSpeed(float toSet)
{
	this->movementSpeed = toSet;
}

void Character::Set_Position(float x, float y)
{
	this->sprite.setPosition(x, y);
}

#pragma endregion

#pragma region Getters

bool Character::Get_CanMoveUp()
{
	return this->canMoveUp;
}

bool Character::Get_CanMoveDown()
{
	return this->canMoveDown;
}

bool Character::Get_CanMoveRight()
{
	return this->canMoveRight;
}

bool Character::Get_CanMoveLeft()
{
	return this->canMoveLeft;
}

Character::Directions Character::Get_Direction()
{
	return this->direction;
}

sf::Sprite Character::Get_Sprite()
{
	return this->sprite;
}

float Character::Get_MovementSpeed()
{
	return this->movementSpeed;
}
#pragma endregion

void Character::SetDirectionFromKeyboardInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->Set_Direction(Character::Directions::Up);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->Set_Direction(Character::Directions::Down);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->Set_Direction(Character::Directions::Left);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->Set_Direction(Character::Directions::Right);
}

bool Character::CheckCollision(std::vector<Wall> walls)
{
	Character::Directions tempDirection;

	for (auto a : walls)
	{
		if (this->sprite.getGlobalBounds().intersects(a.rect.getGlobalBounds()))
		{
			tempDirection = this->Get_Direction();

			if (tempDirection == Character::Directions::Up)
			{
				this->Set_CanMoveUp(false);
				this->sprite.move(0, 1);
				return true;
			}
			else if (tempDirection == Character::Directions::Down)
			{
				this->Set_CanMoveDown(false);
				this->sprite.move(0, -1);
				return true;
			}
			else if (tempDirection == Character::Directions::Left)
			{
				this->Set_CanMoveLeft(false);
				this->sprite.move(1, 0);
				return true;
			}
			else if (tempDirection == Character::Directions::Right)
			{
				this->Set_CanMoveRight(false);
				this->sprite.move(-1, 0);
				return true;
			}
		}
	}

	return false;
}

Character::Directions Character::GetRandomDirection(Character::Directions previuosDirection)
{
	int temp = 0;
	const int range_from = 0, range_to = 3;
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<int> distr(range_from, range_to);

	do
	{
		temp = distr(generator);
	} while (previuosDirection == temp);

	return (Character::Directions)temp;
}