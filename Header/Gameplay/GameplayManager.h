#pragma once
#include "Paddle.h"
#include "Ball/Ball.h"

namespace Gameplay {
	class GameplayManager {
	private:
		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;

		float player2_position_x = 1210.0f;
		float player2_position_y = 300.0f;

		void initialize();

		EventManager* eventManager;

	public:
		Ball* ball = new Ball();
		Paddle* player1 = new Paddle(player1_position_x, player1_position_y);
		Paddle* player2 = new Paddle(player2_position_x, player2_position_y);

		GameplayManager(EventManager* manager);
		void update();
		void render(RenderWindow* game_window);
	};
}
