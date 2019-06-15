#include "Dot.h"

Dot::Dot(bool toSet) : isSuperDot(false)
{
	!isSuperDot ? scoreValue = DOT_POINTS : scoreValue = SUPER_DOT_POINTS;

	circle.setFillColor(sf::Color::White);
	this->isSuperDot = toSet;
	this->isSuperDot ? circle.setRadius(3) : circle.setRadius(1);
}

Dot::Dot(float x, float y) : isSuperDot(false)
{
	!isSuperDot ? scoreValue = DOT_POINTS : scoreValue = SUPER_DOT_POINTS;

	circle.setFillColor(sf::Color::White);
	circle.setRadius(1);
	circle.setPosition(x, y);
}

Dot::Dot(const Dot& d)
{
	this->circle = d.circle;
	this->isSuperDot = d.isSuperDot;
}


Dot::~Dot()
{
}
