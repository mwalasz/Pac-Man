#include "Game.h"

Game::Game() : isPaused(false), scareMode(false), isStart(true), gameOver(false), victory(false),
secondSinceChangeOfMode(0.0f){}

Game::~Game()
{
	DeleteAllocatedGhostsVector();
}

Game::ReturnedActions Game::PacmanLoop()
{
	try
	{
		Pacman pacman;
		InkyBlueGhost* p_blueG = new InkyBlueGhost();
		BlinkyRedGhost* p_redG = new BlinkyRedGhost();
		ClydeOrangeGhost* p_orangeG = new ClydeOrangeGhost();
		PinkyPinkGhost* p_pinkyG = new PinkyPinkGhost();
		p_ghosts.push_back(p_redG);
		p_ghosts.push_back(p_blueG);
		p_ghosts.push_back(p_orangeG);
		p_ghosts.push_back(p_pinkyG);

		while (graphic.main_window.isOpen())
		{
			sf::Time elapsedTime = clock.restart();

			sf::Event event;
			while (graphic.main_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					graphic.main_window.close();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					RessurectGhost(p_ghosts);
					ResetGame(true);
					return Game::Exit;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
					pacman.Set_IsFrightening(!pacman.Get_IsFrightening());

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
					graphic.MuteGame();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
					PauseGameLoop();

				if (event.type == sf::Event::KeyPressed)
					graphic.main_window.clear();
			}

			graphic.main_window.clear();

			CheckIfLevelIsEnded(p_ghosts);

			if (!isPaused && !gameOver && !victory)
			{
				ChangeGhostsMovementSpeeds(p_ghosts, pacman, pacman.Get_IsFrightening());

				MoveCharacters(p_ghosts, pacman);

				if (pacman.DotCollision(labyrinth.Get_Dots_R(), player))
					if(graphic.playMusic)
						sound.PlayDotEatingSound();

				if (pacman.Get_IsFrightening()) //time counting for changing states
				{
					secondSinceChangeOfMode += elapsedTime.asSeconds();

					if (secondSinceChangeOfMode >= SCARE_MODE_DURATION)
					{
						pacman.Set_KilledGhosts(0);
						secondSinceChangeOfMode = 0.0f;

						MakeGhostsVisible(p_ghosts);

						pacman.Set_IsFrightening(false);
					}
				}

				ChangeGhostsTexture(p_ghosts, pacman);

				if (pacman.GhostCollision(p_ghosts, player)) //collision detected, pacman kills covered
				{
					if (!pacman.Get_IsFrightening()) //Ghosts kill
					{
						player.results.Set_LifesRemained(player.results.Get_LifesRemained() - 1);
						pacman.Set_Position(PACMAN_X, PACMAN_Y);
						isStart = true;

						if (player.results.Get_LifesRemained() == 0)
						{
							player.results.SaveToFile(RESULTS_PATH, player.Get_Name(), player.results.Get_TotalScore());
							gameOver = true;
							
							if (graphic.playMusic)
								sound.PlayDieMusic();
						}
					}
				}
			}

			DrawEverything(pacman, p_ghosts);

			if (victory)
			{
				graphic.main_window.draw(graphic.Get_VictoryInfo());

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					RessurectGhost(p_ghosts);
					ResetGame(false);
					return Game::Victory;
				}
			}

			if (!gameOver && !victory)
			{
				if (isPaused)
					graphic.DrawPauseInfo();

				if (isStart)
					graphic.main_window.draw(graphic.Get_StartOfGameInfo());
			}

			if(gameOver)
			{
				if(!victory)
					graphic.main_window.draw(graphic.Get_GameOverInfo());

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					RessurectGhost(p_ghosts);
					ResetGame(false);
					return Game::GameOver;
				}
			}

			graphic.main_window.display();
       
			if (isStart)
			{
				if(!gameOver)
					if(graphic.playMusic)
						sound.PlayIntroMusic();

				graphic.MakeDelayBeforeStartOfGameInfo(isStart);
			}
		}

		delete p_blueG;
		delete p_redG;
		delete p_pinkyG;
		delete p_orangeG;
	}
	catch (std::exception& e)
	{
		std::cerr << "Following error occurred: " << e.what() << std::endl;
	}
}

void Game::MainLoop()
{
	try
	{
		graphic.main_window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pac-Man", sf::Style::Close);

		vectorForGameRestart = labyrinth.Get_Dots();

		Menu menu(SCREEN_WIDTH, SCREEN_HEIGHT);

		while (graphic.main_window.isOpen())
		{
			sf::Event event;
			while (graphic.main_window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						menu.MoveUp();
						break;

					case sf::Keyboard::Down:
						menu.MoveDown();
						break;

					case sf::Keyboard::Return:
						switch (menu.Get_PressedItem())
						{
						case 0:
							if(menu.Get_PlayerName(player, graphic.main_window))
								PacmanLoop();
							break;
						case 1:
							player.results.ReadFromFile(RESULTS_PATH);
							menu.DisplayHighscores(graphic.main_window, player.results);
							break;
						case 2:
							graphic.main_window.close();
							break;
						}
						break;
					}
					break;

				case sf::Event::Closed:
					graphic.main_window.close();
					break;
				}
			}

			graphic.main_window.clear();

			menu.Draw(graphic.main_window);

			graphic.main_window.display();
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Following error occurred: " << e.what() << std::endl;
	}
	
}

void Game::Set_IsPaused(bool toSet)
{
	this->isPaused = toSet;
}

bool Game::Get_IsPaused()
{
	return this->isPaused;
}

void Game::PauseGameLoop()
{
	isPaused = !isPaused;
}

void Game::ResetGame(bool ifSaveToFile)
{
	DeleteAllocatedGhostsVector();
	labyrinth.Set_Dots(vectorForGameRestart);
	victory = false;
	gameOver = false;
	isStart = true;
	Set_IsPaused(false);

	if(ifSaveToFile)
		player.results.SaveToFile(RESULTS_PATH, player.Get_Name(), player.results.Get_TotalScore());

	player.Set_Name("");
	player.results.ResetAllResultsData();
}

void Game::RessurectGhost(std::vector<Ghost*> ghosts)
{
	for (auto a : ghosts)
		a->Set_IsAlive(true);
}

void Game::MakeGhostsVisible(std::vector<Ghost*> ghosts)
{
	for (auto a : ghosts)
		a->Set_IsVisible(true);
}

void Game::ChangeGhostsTexture(std::vector<Ghost*> ghosts, Pacman p)
{
	for (auto a : ghosts)
		a->ChangeTexture(p.Get_IsFrightening());
}

void Game::DeleteAllocatedGhostsVector()
{
	for (auto a : p_ghosts)
		delete a;

	p_ghosts.clear();
}

void Game::ChangeGhostsMovementSpeeds(std::vector<Ghost*> ghosts, Pacman & p, bool isPacmanFrightening)
{
	if (isPacmanFrightening)
		p.Set_MovementSpeed(PACMAN_SPEED_FRIGHTENING);
	else p.Set_MovementSpeed(PACMAN_SPEED_INIT);

	for (auto a : ghosts)
	{
		if(isPacmanFrightening)
			a->Set_MovementSpeed(a->Get_SlowMovementSpeed());
		else a->Set_MovementSpeed(a->Get_NormalMovementSpeed());
	}
}

bool Game::CheckIfEveryGhostIsDead(std::vector<Ghost*> ghosts)
{
	for (auto a : ghosts)
	{
		if (!a->Get_IsAlive())
			continue;
		else return false;
	}
	return true;
}

bool Game::CheckIfLevelIsEnded(std::vector<Ghost*> ghosts)
{
	if (labyrinth.Get_Dots().empty())
	{
		if (CheckIfEveryGhostIsDead(ghosts))
		{
			victory = true;
			return true;
		}
		else return false;
	}
	else return false;
}

void Game::MoveCharacters(std::vector<Ghost*> ghosts, Pacman& p)
{
	p.Move(p.CheckCollision(labyrinth.Get_Walls()));

	for (auto a : ghosts)
		a->Move(a->CheckCollision(labyrinth.Get_Walls()), p);
}

void Game::DrawEverything(Pacman p, std::vector<Ghost*> ghost)
{
	graphic.DrawBackground();
	graphic.DrawDots(labyrinth.Get_Dots());
	graphic.DrawSprite(p.Get_Sprite());
	graphic.DrawText(player.Get_Name(), player.results.Get_TotalScore(), player.results.Get_PassedLevels());
	graphic.DrawLivesRemained(player.results.Get_LifesRemained());

	for (auto a : ghost)
	{
		if(a->Get_IsVisible())
			graphic.DrawSprite(a->Get_Sprite());
	}
}
