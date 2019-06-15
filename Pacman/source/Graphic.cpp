#include "Graphic.h"
#include "Constants.h"

Graphic::Graphic() : playMusic(true)
{
	if (!backgroundTexture.loadFromFile(BACKGROUND_PATH) 
		|| !livesRemainedTexture.loadFromFile(SPRITE_SHEETS_PATH + PACMAN_SPRITESHEET))
		throw NoBackgroundPictureException();
	else
	{
		if (!boingFont.loadFromFile(FONTS_PATH + BOING_FONT))
			throw NoFontLoadedException();
		else
		{
			playerLabel.setFont(boingFont);
			playerLabel.setFillColor(sf::Color::Yellow);
			playerLabel.setStyle(sf::Text::Bold);
			playerLabel.setCharacterSize(FONT_SIZE);
			playerLabel.setString(PLAYER_LABEL);
			playerLabel.setPosition(X_INITIAL_POSITION_OF_TEXT, Y_INITIAL_POSITION_OF_TEXT);

			playerName.setFont(boingFont);
			playerName.setCharacterSize(FONT_SIZE);
			playerName.setPosition(X_INITIAL_POSITION_OF_TEXT + 20.0f, Y_INITIAL_POSITION_OF_TEXT + INTERSPACE_BETWEEN_TEXTS/2);

			scoreLabel.setFont(boingFont);
			scoreLabel.setFillColor(sf::Color::Yellow);
			scoreLabel.setStyle(sf::Text::Bold);
			scoreLabel.setCharacterSize(FONT_SIZE);
			scoreLabel.setString(SCORE_LABEL);
			scoreLabel.setPosition(X_INITIAL_POSITION_OF_TEXT, Y_INITIAL_POSITION_OF_TEXT + INTERSPACE_BETWEEN_TEXTS * 1.5);

			scorePoints.setFont(boingFont);
			scorePoints.setCharacterSize(30);
			scorePoints.setPosition(X_INITIAL_POSITION_OF_TEXT + 40.0f, Y_INITIAL_POSITION_OF_TEXT + INTERSPACE_BETWEEN_TEXTS * 2);

			levelLabel.setFont(boingFont);
			levelLabel.setFillColor(sf::Color::Yellow);
			levelLabel.setStyle(sf::Text::Bold);
			levelLabel.setCharacterSize(FONT_SIZE);
			levelLabel.setString(LEVEL_LABEL);
			levelLabel.setPosition(X_INITIAL_POSITION_OF_TEXT, Y_INITIAL_POSITION_OF_TEXT + INTERSPACE_BETWEEN_TEXTS * 3);

			levelNumber.setFont(boingFont);
			levelNumber.setCharacterSize(FONT_SIZE);
			levelNumber.setPosition(X_INITIAL_POSITION_OF_TEXT + 40.0f, Y_INITIAL_POSITION_OF_TEXT + INTERSPACE_BETWEEN_TEXTS * 3.5);
	
			livesLabel.setFont(boingFont);
			livesLabel.setFillColor(sf::Color::Yellow);
			livesLabel.setStyle(sf::Text::Bold);
			livesLabel.setCharacterSize(FONT_SIZE);
			livesLabel.setString(LIVES_LABEL);
			livesLabel.setPosition(X_INITIAL_POSITION_OF_TEXT, Y_INITIAL_POSITION_OF_TEXT + INTERSPACE_BETWEEN_TEXTS * 6.5);

			pauseInfo.setFont(boingFont);
			pauseInfo.setFillColor(sf::Color::Red);
			pauseInfo.setStyle(sf::Text::Bold);
			pauseInfo.setCharacterSize(BIG_FONT_SIZE);
			pauseInfo.setString(PAUSE_LABEL);
			pauseInfo.setPosition(215, SCREEN_HEIGHT / 2 - 70);

			startOfGameInfo.setFont(boingFont);
			startOfGameInfo.setFillColor(sf::Color::White);
			startOfGameInfo.setCharacterSize(FONT_SIZE);
			startOfGameInfo.setString(START_OF_GAME_INFO);
			startOfGameInfo.setPosition(355, SCREEN_HEIGHT / 2 + 15);

			gameOverInfo.setFont(boingFont);
			gameOverInfo.setFillColor(sf::Color::Red);
			gameOverInfo.setCharacterSize(FONT_SIZE);
			gameOverInfo.setString(GAME_OVER_INFO);
			gameOverInfo.setPosition(355, SCREEN_HEIGHT / 2 + 15);

			victoryInfo.setFont(boingFont);
			victoryInfo.setFillColor(sf::Color::Green);
			victoryInfo.setCharacterSize(BIG_FONT_SIZE);
			victoryInfo.setStyle(sf::Text::Bold);
			victoryInfo.setString(WIN_INFO);
			victoryInfo.setPosition(285, SCREEN_HEIGHT / 2 - 70);

			background.setTexture(backgroundTexture);
			sizeOfBackground = backgroundTexture.getSize();
			main_window.setSize(sizeOfBackground);
			main_window.setTitle("Pac-Man");

			livesRemained.setTexture(livesRemainedTexture);
			livesRemained.setTextureRect(sf::IntRect(4 * GRAPHIC_SIZE, 0, GRAPHIC_SIZE, GRAPHIC_SIZE));
			livesRemained.setPosition(X_INITIAL_POSITION_OF_TEXT + 20.0f, Y_INITIAL_POSITION_OF_TEXT + INTERSPACE_BETWEEN_TEXTS * 7.2);
		}
	}
}

Graphic::~Graphic()
{
}

void Graphic::DrawPauseInfo()
{
	main_window.draw(pauseInfo);
}

void Graphic::DrawDots(std::vector<Dot> dotsToDraw)
{
	for (auto a : dotsToDraw)
		main_window.draw(a.circle);
}

void Graphic::DrawSprite(sf::Sprite spriteToDraw)
{
	main_window.draw(spriteToDraw);
}

void Graphic::DrawBackground()
{
    main_window.draw(background);
}

void Graphic::DrawText(std::string nameToSet, unsigned int pointsToSet, unsigned int levelToSet)
{
	scorePoints.setString(std::to_string(pointsToSet));
	playerName.setString(nameToSet);
	levelNumber.setString(std::to_string(levelToSet));

	main_window.draw(playerLabel);
	main_window.draw(playerName);
	main_window.draw(scoreLabel);
	main_window.draw(scorePoints);
	main_window.draw(levelLabel);
	main_window.draw(levelNumber);
	main_window.draw(livesLabel);
}

void Graphic::DrawLivesRemained(unsigned int howManyRemained)
{
	for (unsigned int i = 1; i <= howManyRemained; i++)
	{
		livesRemained.setPosition(X_INITIAL_POSITION_OF_TEXT + (30.0f * i), Y_INITIAL_POSITION_OF_TEXT + INTERSPACE_BETWEEN_TEXTS * 7.2);
		main_window.draw(livesRemained);
	}
}

void Graphic::MakeDelayBeforeStartOfGameInfo(bool & isStart)
{
	sf::Clock clock;
	while (clock.getElapsedTime() <= sf::seconds(4)){}
	isStart = false;
}

void Graphic::MuteGame()
{
	playMusic = !playMusic;
}

sf::Text Graphic::Get_StartOfGameInfo()
{
	return this->startOfGameInfo;
}

sf::Text Graphic::Get_GameOverInfo()
{
	return this->gameOverInfo;
}

sf::Text Graphic::Get_VictoryInfo()
{
	return victoryInfo;
}