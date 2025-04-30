#include "../../Header/Event/EventManager.h"

using namespace sf;
namespace Event {
	
	void EventManager::pollEvents(RenderWindow* game_window)
	{
		sf::Event event;
		while (game_window->pollEvent(event))
		{
			//Handle the close window event
			if (event.type == sf::Event::Closed)
			{
				game_window->close();
			}

			//Check for Escape Key
			if (isKeyPressed(Keyboard::Escape))
			{
				game_window->close();
			}
		}
	}

	bool EventManager::isKeyPressed(Keyboard::Key key)
	{
		//Detect if a specific key is pressed
		return Keyboard::isKeyPressed(key);
	}
}