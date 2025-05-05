#pragma once
#include "Paddle/Paddle.h"
#include "Ball/Ball.h"
#include "Boundary/Boundary.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Utility/TimeService.h"
#include "../../Header/UI/UIService.h"
using namespace Event;
using namespace Utility;
using namespace UI;

namespace Gameplay {
	class GameplayManager {
	private:
		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;

		float player2_position_x = 1210.0f;
		float player2_position_y = 300.0f;

		void initialize();

		EventManager* event_manager;
		Boundary* boundary = new Boundary();
		TimeService* time_service;
		UIService* ui_service = new UIService;

	public:
		Ball* ball = new Ball();
		Paddle* player1 = new Paddle(player1_position_x, player1_position_y);
		Paddle* player2 = new Paddle(player2_position_x, player2_position_y);

		GameplayManager(EventManager* manager);

		void UpdateScore();
		void resetPlayers();

		void update();
		void render(RenderWindow* game_window);
	};
}
