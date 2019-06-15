#pragma once
#include <string>
#include "Constants.h"
#include "Exceptions.h"
#include "Ghost.h"
#include "Pacman.h"

//chases pacman
class ClydeOrangeGhost : public Ghost
{
public:
	ClydeOrangeGhost();
	~ClydeOrangeGhost();

	void KilledRightNow(Player& player, int howManyKilled);
	void Move(bool isCollision, Pacman pacman);
};