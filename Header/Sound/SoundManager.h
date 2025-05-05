#pragma once
#include <SFML/Audio.hpp>
#include <string>

namespace Sound {
	using namespace sf;
	using namespace std;

	enum class SoundType
	{
		BALL_BOUNCE
	};

	class SoundManager
	{
	private:
		static Music backgroundMusic;
		static sf::Sound soundEffect;
		static SoundBuffer ballBounce;

		static float backgroundMusicVolume;
		static const string ballBouncePath;

		
		static void LoadSoundFromFile();

	public:
		static void Initialize();
		static void PlaySoundEffect(SoundType soundType);
		static void PlayBackgroundMusic();
	};
}