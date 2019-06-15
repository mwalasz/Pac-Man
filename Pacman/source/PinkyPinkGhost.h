#pragma once
#include "Constants.h"
#include "Exceptions.h"
#include "Ghost.h"

//runs away
class PinkyPinkGhost : public Ghost
{
public:
	PinkyPinkGhost();
	~PinkyPinkGhost();

	void KilledRightNow(Player& player, int howManyKilled);
	void Move(bool isCollision, Pacman pacman);
};