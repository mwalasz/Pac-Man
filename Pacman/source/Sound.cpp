#include "Sound.h"

Sound::Sound()
{
	if (!backgroundSiren.openFromFile(SOUNDS_PATH + SIREN_SOUND) 
		|| !dieBuffer.loadFromFile(SOUNDS_PATH + DEATH_SOUND)
		|| !dotBuffer.loadFromFile(SOUNDS_PATH + COIN_SOUND)
		|| !introBuffer.loadFromFile(SOUNDS_PATH + INTRO_SOUND))
		throw NoSoundLoadedException();
	else
	{
		introSound.setBuffer(introBuffer);
		introSound.setVolume(50);

		dotEatingSound.setBuffer(dotBuffer);
		dotEatingSound.setVolume(40);
		
		dieSound.setBuffer(dieBuffer);
		dieSound.setVolume(50);

		backgroundSiren.setVolume(40);
		backgroundSiren.setLoop(true);
	}
}

void Sound::PlayIntroMusic()
{
	introSound.play();
}

void Sound::PlayDieMusic()
{
	dieSound.play();
}

void Sound::PlayDotEatingSound()
{
	dotEatingSound.play();
}

void Sound::PlayBackgroundSiren()
{
	backgroundSiren.play();
}
