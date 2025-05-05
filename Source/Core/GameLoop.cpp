#include "../../Header/Core/GameLoop.h"

namespace Core {
	using namespace Sound;

	void GameLoop::initialize()
	{
		gameWindowManager = new GameWindowManager();
		eventManager = new EventManager();
		gameplayManager = new GameplayManager(eventManager);
		SoundManager::Initialize();

		gameWindowManager->initialize();
		SoundManager::PlayBackgroundMusic();
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
		gameplayManager->update();
	}

	void GameLoop::render()
	{
		gameWindowManager->clearGameWindow();
		
		//render the paddles and ball
		gameplayManager->render(gameWindowManager->getGameWindow());

		gameWindowManager->displayGameWindow();
	}
}