#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Exceptions.h"
#include "Dot.h"

class Graphic
{
public:
	Graphic();
	~Graphic();

	bool playMusic;
	sf::RenderWindow main_window;

	void DrawPauseInfo();
	void DrawDots(std::vector<Dot> dotsToDraw);
	void DrawSprite(sf::Sprite spriteToDraw);
	void DrawBackground();
	void DrawText(std::string playerName, unsigned int scorePoints, unsigned int levelToSet);
	void DrawLivesRemained(unsigned int howManyRemained);
	void MakeDelayBeforeStartOfGameInfo(bool& isStart);
	void MuteGame();

	sf::Text Get_StartOfGameInfo();
	sf::Text Get_GameOverInfo();
	sf::Text Get_VictoryInfo();

private:
	sf::Vector2u sizeOfBackground;
	sf::Texture backgroundTexture;
	sf::Texture livesRemainedTexture;
	sf::Sprite background;
	sf::Sprite livesRemained;
	sf::Font boingFont;
	sf::Text playerLabel;
	sf::Text playerName;
	sf::Text scoreLabel;
	sf::Text scorePoints;
	sf::Text levelLabel;
	sf::Text levelNumber;
	sf::Text livesLabel;
	sf::Text pauseInfo;
	sf::Text startOfGameInfo;
	sf::Text gameOverInfo;
	sf::Text victoryInfo;
};