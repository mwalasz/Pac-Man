#pragma once

#include <regex>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Exceptions.h"
#include "Game.h"
#include "Pacman.h"

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void Draw(sf::RenderWindow& window);
	void DisplayHighscores(sf::RenderWindow& window, Results result);
	
	void MoveUp();
	void MoveDown();
	
	bool Get_PlayerName(Player& player, sf::RenderWindow& window);
	int Get_PressedItem();

	Pacman pacman;

private:
	int selectedItemIndex;
	
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_MENU_OPTIONS];
	sf::Text mainTitle;
	sf::Text highScoresMainTitle;
	sf::Text numberOfResultToDisply;
	sf::Text nameToDisplay;
	sf::Text scoreToDisplay;
	sf::Text comunicatAboutNoData;

	sf::Text titleEnterName;
	sf::Text enteredName;
	sf::Text wrongNameEntered;
	sf::Text tooLongText;

	sf::RectangleShape rect;
};