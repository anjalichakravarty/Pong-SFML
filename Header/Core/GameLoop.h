#pragma once
#include "../../SFML/include/SFML/Graphics.hpp"
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"

using namespace sf;
using namespace Core;
using namespace Event;
using namespace std;

namespace Core {
	class GameLoop {
	private:
		GameWindowManager* gameWindowManager;
		EventManager* eventManager;

	public:
		void initialize();

		bool isGameRunning();
		void pollEvent();
		void update();
		void render();
	};
}
