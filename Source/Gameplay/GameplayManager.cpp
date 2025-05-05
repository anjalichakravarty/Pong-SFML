#include "../../Header/Gameplay/GameplayManager.h"
#include "../../Header/Event/EventManager.h"
using namespace Event;

namespace Gameplay {
	GameplayManager::GameplayManager(EventManager* manager)
	{
		time_service = new TimeService();
		time_service->initialize();
		event_manager = manager;
		
	}

	void GameplayManager::initialize()
	{
		ball = new Ball();
		player1 = new Paddle(player1_position_x, player1_position_y);
		player2 = new Paddle(player2_position_x, player2_position_y);
	}

	void GameplayManager::update()
	{
		time_service->update();
		player1->update(event_manager->isKeyPressed(Keyboard::W), event_manager->isKeyPressed(Keyboard::S), time_service);
		player2->update(event_manager->isKeyPressed(Keyboard::Up), event_manager->isKeyPressed(Keyboard::Down), time_service);
		ball->update(player1, player2, time_service);
		UpdateScore();
		ui_service->update();
	}

	void GameplayManager::UpdateScore()
	{
		//Left side out - Player2 scores
		if (ball->isLeftCollisionOccurred())
		{
			ui_service->incrementPlayer2Score();
			ball->updateLeftCollisionState(false);
			resetPlayers();
		}

		//Right side out - Player1 scores
		if (ball->isRightCollisionOccurred())
		{
			ui_service->incrementPlayer1Score();
			ball->updateRightCollisionState(false);
			resetPlayers();
		}
	}

	void GameplayManager::resetPlayers()
	{
		player1->reset(player1_position_x, player1_position_y);
		player2->reset(player2_position_x, player2_position_y);
	}

	void GameplayManager::render(RenderWindow* game_window)
	{
		boundary->render(game_window);
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);
		ui_service->render(game_window);
	}

	
}