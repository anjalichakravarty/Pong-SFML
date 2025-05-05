#include "../../Header/Sound/SoundManager.h"
#include <iostream>

namespace Sound {

	using namespace sf;
	using namespace std;

	SoundBuffer SoundManager::ballBounce;
	sf::Sound SoundManager::soundEffect;

	Music SoundManager::backgroundMusic;
	const string SoundManager::bgmPath = "Assets/Sounds/Pong_bgm.mp3";
	float SoundManager::backgroundMusicVolume = 50.0f;

	const string SoundManager::ballBouncePath = "Assets/Sounds/Ball_Bounce.wav";

	void SoundManager::Initialize()
	{
		LoadSoundFromFile();
	}

	void SoundManager::LoadSoundFromFile()
	{
		if (!ballBounce.loadFromFile(ballBouncePath))
		{
			cerr << "Error loading sound file: " << ballBouncePath << endl;
		}

		if (!backgroundMusic.openFromFile(bgmPath))
		{
			cerr << "Error loading background music file: " << bgmPath << endl;
			return;
		}
	}

	void SoundManager::PlaySoundEffect(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BALL_BOUNCE:
			soundEffect.setBuffer(ballBounce);
			break;

		default:
			cerr << "Invalid sound type" << endl;
			return;
		}

		soundEffect.play();
	}

	void SoundManager::PlayBackgroundMusic()
	{
		backgroundMusic.setVolume(backgroundMusicVolume);
		backgroundMusic.setLoop(true);
		backgroundMusic.play();
	}
}