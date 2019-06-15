#include "Food.h"

Food::Food() : isPickedUp(false), scoreValue(0)
{
}

Food::~Food()
{
}

sf::Sprite Food::Get_Sprite()
{
	return this->sprite;
}