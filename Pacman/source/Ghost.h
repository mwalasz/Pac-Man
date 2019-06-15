#pragma once
#include "Character.h"
#include "Player.h"
#include "Pacman.h"

class Pacman;

class Ghost : public Character
{
public:
	Ghost();
	virtual ~Ghost() = 0;

	virtual void Move(bool isCollision, Pacman pacman) = 0;
	virtual void KilledRightNow(Player& player, int howManyKilled) = 0;

	void ChangeTexture(bool isScared);
	Results::PointsForKilledGhost HowManyPointsAddForKillingManyGhost(int howManyKilled);

	void Set_IsVisible(bool toSet);
	bool Get_IsVisible();

	void Set_IsAlive(bool toSet);
	bool Get_IsAlive();

	float Get_SlowMovementSpeed();
	float Get_NormalMovementSpeed();

protected:
	sf::Vector2f NormaliseVector(sf::Vector2f source);
	Character::Directions CalculateNextMoveForFollowing(Pacman pacman, bool isCollision);
	Character::Directions CalculateNextMoveForRunningAway(Pacman pacman);
	bool CheckIfCanGoInThatDirection(Character::Directions direction);

	bool isAlive;
	bool isVisible;
	float slowMovementSpeed;
	float normalMovementSpeed;
};