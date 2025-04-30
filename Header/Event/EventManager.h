#pragma once

#include "../../SFML/include/SFML/Graphics.hpp"

using namespace sf;

namespace Event {
	class EventManager {
	public:
		void pollEvents(RenderWindow* gameWindow); //Process all events
		bool isKeyPressed(Keyboard::Key key); // Check specific key
	};
}
