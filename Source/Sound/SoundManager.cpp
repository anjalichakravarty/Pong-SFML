#include "../../Header/Sound/SoundManager.h"
#include <iostream>

namespace Sound {

	using namespace sf;
	using namespace std;

	SoundBuffer SoundManager::ballBounce;
	sf::Sound SoundManager::soundEffect;

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
}