#pragma once
#include <iostream>
#include "Food.h"
#include "Constants.h"

class Dot : public Food
{
public:
	Dot(bool toSet);
	Dot(float x, float y);
	Dot(const Dot& d);
	~Dot();

	bool isSuperDot;

	sf::CircleShape circle;
};

