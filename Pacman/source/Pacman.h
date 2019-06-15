#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <vector>
#include "Character.h"
#include "Constants.h"
#include "Exceptions.h"
#include "Wall.h"
#include "Player.h"
#include "Dot.h"
#include "Ghost.h"

class Ghost;

class Pacman : public Character
{
public:
	Pacman();
	~Pacman();

	void Move(bool isCollision);
	void TeleportBetweenExits();
	bool DotCollision(std::vector<Dot> & dots, Player & player);

	bool GhostCollision(std::vector<Ghost*> ghosts, Player& player);

	void Set_IsFrightening(bool toSet);
	bool Get_IsFrightening();

	void DeadAnimation(sf::RenderWindow & window);

	void Set_KilledGhosts(int toSet);
	int Get_KilledGhosts();

private:
	int killedGhosts;
	bool isFrightening;
	sf::Texture deadTexture;
};