#include "Wall.h"

Wall::Wall(int x_, int y_, int l, int h)
{
	this->x = x_;
	this->y = y_;
	this->length = l;
	this->height = h;
	rect.setPosition(float(x_), float(y_));
	const sf::Vector2f size(l, h);
}