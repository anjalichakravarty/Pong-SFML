#include "../../Header/Core/GameLoop.h"

namespace Core {
	void GameLoop::initialize()
	{
		gameWindowManager = new GameWindowManager();
		eventManager = new EventManager();

		gameWindowManager->initialize();
	}

	bool GameLoop::isGameRunning()
	{
		return gameWindowManager->isGameRunning();
	}

	void GameLoop::pollEvent()
	{
		eventManager->pollEvents(gameWindowManager->getGameWindow());
	}

	void GameLoop::update()
	{

	}

	void GameLoop::render()
	{
		gameWindowManager->clearGameWindow();
		gameWindowManager->displayGameWindow();
	}
}