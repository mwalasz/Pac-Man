#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"

class Food
{
public:
	Food();
	~Food();

	sf::Sprite Get_Sprite();
	bool isPickedUp;

protected:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::RectangleShape rect;

	int scoreValue;
};

