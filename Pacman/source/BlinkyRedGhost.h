#pragma once
#include "Constants.h"
#include "Exceptions.h"
#include "Ghost.h"

//chases pacman
class BlinkyRedGhost : public Ghost
{
public:
	BlinkyRedGhost();
	~BlinkyRedGhost();

	void KilledRightNow(Player& player, int howManyKilled);

	void Move(bool isCollision, Pacman pacman);
};