#pragma once

#include "SFML/Graphics.hpp"

class Wall
{
public:
	Wall(int x, int y, int l, int h);

	sf::Sprite sprite;
	sf::RectangleShape rect;

	int x;
	int y;
	int length;
	int height;
};