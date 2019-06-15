#pragma once
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <memory>
#include "InkyBlueGhost.h"
#include "ClydeOrangeGhost.h"
#include "PinkyPinkGhost.h"
#include "BlinkyRedGhost.h"
#include "Labirynth.h"
#include "Wall.h"
#include "Dot.h"
#include "Graphic.h"
#include "Pacman.h"
#include "Player.h"
#include "Menu.h"
#include "Sound.h"

class Game
{
public:
	Game();
	~Game();

	enum ReturnedActions {GameOver, Exit, Victory, EnteredName};

	/* Loops */
	void MainLoop();
	ReturnedActions PacmanLoop();
	void PauseGameLoop();

	/* Methods */
	void DrawEverything(Pacman p, std::vector<Ghost*> ghost);
	void Set_IsPaused(bool toSet);
	bool Get_IsPaused();
	void ResetGame(bool ifSaveToFile);
	void RessurectGhost(std::vector<Ghost*> ghosts);
	void MakeGhostsVisible(std::vector<Ghost*> ghosts);
	void ChangeGhostsTexture(std::vector<Ghost*> ghosts, Pacman p);
	void DeleteAllocatedGhostsVector();
	void ChangeGhostsMovementSpeeds(std::vector<Ghost*> ghosts, Pacman & p, bool isPacmanFrightening);
	bool CheckIfEveryGhostIsDead(std::vector<Ghost*> ghosts);
	bool CheckIfLevelIsEnded(std::vector<Ghost*> ghosts);
	void MoveCharacters(std::vector<Ghost*> ghosts, Pacman& p);

private:
	std::vector<Ghost*> p_ghosts;
	std::vector<Dot> vectorForGameRestart;
	
	sf::Clock clock;
	Graphic graphic;
	Sound sound;
	Labyrinth labyrinth;
	Player player;

	bool scareMode;
	bool isPaused;
	bool isStart;
	bool gameOver;
	bool victory;

	float secondSinceChangeOfMode;
};