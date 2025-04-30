#include "../../Header/Event/EventManager.h"
#include <iostream>

using namespace sf;
using namespace std;
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

			//Handle left mouse button click
			if (isLeftMouseButtonClicked())
			{
				Vector2i position = Mouse::getPosition(*game_window);

				//Log the mouse position
				cout << "Left mouse click at: " << position.x << "," << position.y << endl;
			}
		}
	}

	bool EventManager::isKeyPressed(Keyboard::Key key)
	{
		//Detect if a specific key is pressed
		return Keyboard::isKeyPressed(key);
	}

	bool EventManager::isLeftMouseButtonClicked()
	{
		//Detect if the left mouse button is clicked
		return(Mouse::isButtonPressed(Mouse::Left));
	}
}