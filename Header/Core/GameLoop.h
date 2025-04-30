#pragma once
#include "../../SFML/include/SFML/Graphics.hpp"
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Gameplay/GameplayManager.h"

using namespace sf;
using namespace Core;
using namespace Event;
using namespace std;
using namespace Gameplay;

namespace Core {
	class GameLoop {
	private:
		GameWindowManager* gameWindowManager;
		EventManager* eventManager;
		GameplayManager* gameplayManager;

	public:
		void initialize();

		bool isGameRunning();
		void pollEvent();
		void update();
		void render();
	};
}
