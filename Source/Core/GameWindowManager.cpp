#include "../../Header/Core/GameWindowManager.h"

namespace Core {
	void GameWindowManager::initialize()
	{
		//Allocate memory for the render window object
		game_window = new RenderWindow();
		//Set up the window with configured properties
		createGameWindow();
	}

	void GameWindowManager::createGameWindow()
	{
		//Creating the window with specified dimensions and title
		game_window->create(
			VideoMode::getDesktopMode(),
			game_title,
			Style::Fullscreen
		);
	}

	bool GameWindowManager::isGameRunning()
	{
		//Return true if window is open, false if closed
		return game_window->isOpen();
	}

	void GameWindowManager::render()
	{
		//This will handle all the drawing operations
		//Clear window with orange color(R:200, G:50, B:50, A:255)
		game_window->clear(Color(200, 50, 50, 255));

		//draw shapes, sprites

		//Display the changes
		game_window->display();
	}

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_window;
	}
}