#include "Ghost.h"

Ghost::Ghost() : isVisible(true), isAlive(true) {}

Ghost::~Ghost() {}

void Ghost::ChangeTexture(bool isScared)
{
	if (isScared && isAlive)
	{
		this->sprite.setTextureRect(sf::IntRect(11 * GRAPHIC_SIZE, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
	}
	else
	{
		this->sprite.setTextureRect(sf::IntRect(0 * GRAPHIC_SIZE, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
	}
}

Results::PointsForKilledGhost Ghost::HowManyPointsAddForKillingManyGhost(int howManyKilled)
{
	switch (howManyKilled)
	{
	case 4:
		return Results::PointsForKilledGhost::FOUR;
	case 3:
		return Results::PointsForKilledGhost::THREE;
	case 2:
		return Results::PointsForKilledGhost::TWO;
	case 1:
		return Results::PointsForKilledGhost::ONE;
	case 0:
	default:
		break;
	}
}

void Ghost::Set_IsVisible(bool toSet)
{
	this->isVisible = toSet;
}

bool Ghost::Get_IsVisible()
{
	return this->isVisible;
}

void Ghost::Set_IsAlive(bool toSet)
{
	this->isAlive = toSet;
}

bool Ghost::Get_IsAlive()
{
	return this->isAlive;
}

float Ghost::Get_SlowMovementSpeed()
{
	return this->slowMovementSpeed;
}

float Ghost::Get_NormalMovementSpeed()
{
	return this->normalMovementSpeed;
}

sf::Vector2f Ghost::NormaliseVector(sf::Vector2f source)
{
	float length = std::hypot(source.x, source.y);
	if (length != 0)
		source /= length;

	return source;
}

Character::Directions Ghost::CalculateNextMoveForFollowing(Pacman pacman, bool isCollision)
{
	sf::Vector2f direction = NormaliseVector(pacman.Get_Sprite().getPosition() - this->sprite.getPosition());

	Character::Directions currentDirection = this->Get_Direction();
	Character::Directions nextMove;

	bool xIsBigger = false;

	if (std::fabs(direction.x) >= std::fabs(direction.y))
		xIsBigger = true;
	else xIsBigger = false;

	if (xIsBigger)
	{
		if (direction.x > 0)
			nextMove = Character::Directions::Right;
		else nextMove = Character::Directions::Left;
	}
	else
	{
		if (direction.y > 0)
			nextMove = Character::Directions::Down;
		else nextMove = Character::Directions::Up;
	}

	if ((nextMove == Character::Directions::Down && !this->Get_CanMoveDown()) || 
		(nextMove == Character::Directions::Up && !this->Get_CanMoveUp()))
	{
		if (this->Get_CanMoveLeft())
			nextMove = Character::Directions::Left;
		else if (this->Get_CanMoveRight())
			nextMove = Character::Directions::Right;
	}
	else if ((nextMove == Character::Directions::Left && !this->Get_CanMoveLeft()) ||
		(nextMove == Character::Directions::Right && !this->Get_CanMoveRight()))
	{
		if (this->Get_CanMoveUp())
			nextMove = Character::Directions::Up;
		else if (this->Get_CanMoveDown())
			nextMove = Character::Directions::Down;
	}

	if (currentDirection == nextMove)
		nextMove = GetRandomDirection(currentDirection);

	return nextMove;
}

Character::Directions Ghost::CalculateNextMoveForRunningAway(Pacman pacman)
{
	sf::Vector2f direction = NormaliseVector(pacman.Get_Sprite().getPosition() - this->sprite.getPosition());

	Character::Directions currentDirection = this->Get_Direction();
	Character::Directions nextMove;

	bool xIsBigger = false;

	if (std::fabs(direction.x) >= std::fabs(direction.y))
		xIsBigger = true;
	else xIsBigger = false;

	if (xIsBigger)
	{
		if (direction.x > 0)
			nextMove = Character::Directions::Left;
		else nextMove = Character::Directions::Right;
	}
	else
	{
		if (direction.y > 0)
			nextMove = Character::Directions::Up;
		else nextMove = Character::Directions::Down;
	}

	if ((nextMove == Character::Directions::Down && !this->Get_CanMoveDown()) ||
		(nextMove == Character::Directions::Up && !this->Get_CanMoveUp()))
	{
		if (this->Get_CanMoveLeft())
			nextMove = Character::Directions::Left;
		else if (this->Get_CanMoveRight())
			nextMove = Character::Directions::Right;
	}
	else if ((nextMove == Character::Directions::Left && !this->Get_CanMoveLeft()) ||
		(nextMove == Character::Directions::Right && !this->Get_CanMoveRight()))
	{
		if (this->Get_CanMoveUp())
			nextMove = Character::Directions::Up;
		else if (this->Get_CanMoveDown())
			nextMove = Character::Directions::Down;
	}

	if (currentDirection == nextMove)
		nextMove = GetRandomDirection(currentDirection);

	return nextMove;
}

bool Ghost::CheckIfCanGoInThatDirection(Character::Directions direction)
{
	switch (direction)
	{
	case Character::Directions::Up:
		return this->Get_CanMoveUp();
	case Character::Directions::Down:
		return this->Get_CanMoveDown();
	case Character::Directions::Left:
		return this->Get_CanMoveLeft();
	case Character::Directions::Right:
		return this->Get_CanMoveRight();
	}
}
