#pragma once
#include "Ghost.h"
#include "Constants.h"
#include "Exceptions.h"

//acts randomly
class InkyBlueGhost : public Ghost
{
public:
	InkyBlueGhost();
	~InkyBlueGhost();

	void KilledRightNow(Player& player, int howManyKilled);
	void Move(bool isCollision, Pacman pacman);
};