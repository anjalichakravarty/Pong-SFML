#pragma once
#include "../../SFML/include/SFML/Graphics.hpp"
#include "../../Header/Gameplay/Paddle.h"

using namespace sf;
using namespace std;

namespace Gameplay {
	class Ball {
	private:
		Texture pong_ball_texture;
		Sprite pong_ball_sprite;

		string texture_path = "Assets/Textures/Ball.png";

		float ball_speed = 0.5f;
		Vector2f velocity = Vector2f(ball_speed, ball_speed);

		const float scale_x = 0.06f;
		const float scale_y = 0.06f;

 		const float position_x = 615.0f;
		const float position_y = 335.0f;

		void loadTexture();
		void initializeVariables();

		void move();

	public:
		Ball();

		void update();
		void render(RenderWindow* game_window);
	};
}
