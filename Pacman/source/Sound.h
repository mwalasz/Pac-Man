#pragma once
#include "SFML/Audio.hpp"
#include "Exceptions.h"
#include "Constants.h"

class Sound
{
public:
	Sound();

	void PlayIntroMusic();
	void PlayDieMusic();
	void PlayDotEatingSound();
	void PlayBackgroundSiren();

private:
	sf::SoundBuffer backgroundBuffer;
	sf::SoundBuffer dotBuffer;
	sf::SoundBuffer introBuffer;
	sf::SoundBuffer dieBuffer;

	sf::Sound introSound;
	sf::Sound dieSound;

	sf::Sound dotEatingSound;
	sf::Music backgroundSiren;
};

