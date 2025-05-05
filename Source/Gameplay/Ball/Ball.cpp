#include "../../Header/Gameplay/Ball/Ball.h"
#include <iostream>
#include "../../../Header/Utility/TimeService.h"
using namespace Utility;

using namespace sf;

namespace Gameplay {
	Ball::Ball()
	{
		loadTexture();
		initializeVariables();
	}

	void Ball::render(RenderWindow* game_window)
	{
		game_window->draw(pong_ball_sprite);
	}

	void Ball::loadTexture()
	{
		if (!pong_ball_texture.loadFromFile(texture_path))
		{
			throw runtime_error("Failed to load ball texture!");
		}
	}

	void Ball::initializeVariables()
	{
		pong_ball_sprite.setTexture(pong_ball_texture); //Link texture to sprite
		pong_ball_sprite.setScale(scale_x, scale_y); //Set size
		pong_ball_sprite.setPosition(position_x, position_y); //Set position

		current_state = BallState::Idle;
	}

	void Ball::move(TimeService* time_service)
	{
		updateDelayTime(time_service->getDeltaTime());

		pong_ball_sprite.move(velocity * time_service->getDeltaTime() * speed_multiplier);
	}

	void Ball::updateDelayTime(float delta_time)
	{
		if (current_state == BallState::Idle)
		{
			elapsed_delay_time += delta_time;
			if (elapsed_delay_time >= delta_time)
			{
				current_state = BallState::Moving;
			}
			else
			{
				return;
			}
		}
	}

	void Ball::update(Paddle* player1, Paddle* player2, TimeService* time_service)
	{
		move(time_service);
		onCollision(player1, player2);
	}

	bool Ball::isLeftCollisionOccurred()
	{
		return had_left_collision;
	}

	void Ball::updateLeftCollisionState(bool value)
	{
		had_left_collision = value;
	}

	bool Ball::isRightCollisionOccurred()
	{
		return had_right_collision;
	}

	void Ball::updateRightCollisionState(bool value)
	{
		had_right_collision = value;
	}

	void Ball::handlePaddleCollision(Paddle* player1, Paddle* player2)
	{
		//1. Get our sprites
		const RectangleShape& player1Paddle = player1->getPaddleSprite();
		const RectangleShape& player2Paddle = player2->getPaddleSprite();

		//2. Check their bounds
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
		FloatRect player1_bounds = player1Paddle.getGlobalBounds();
		FloatRect player2_bounds = player2Paddle.getGlobalBounds();

		//3. Handle collision
		if (ball_bounds.intersects(player1_bounds) && velocity.x < 0)
		{
			velocity.x = -velocity.x; //Bounce
		}

		if (ball_bounds.intersects(player2_bounds) && velocity.x > 0)
		{
			velocity.x = -velocity.x; //Reverse horizontal direction
		}
	}

	void Ball::handleBoundaryCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if ((ball_bounds.top <= top_boundary && velocity.y < 0) ||
			(ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0))
		{
			velocity.y = -velocity.y;
		}
	}

	void Ball::handleOutOfBoundCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if (ball_bounds.left <= left_boundary)
		{
			updateLeftCollisionState(true);
			reset();
		}
		else if (ball_bounds.left + ball_bounds.width >= right_boundary)
		{
			updateRightCollisionState(true);
			reset();
		}
	}

	void Ball::reset()
	{
		pong_ball_sprite.setPosition(center_position_x, center_position_y);
		velocity = Vector2f(ball_speed, ball_speed);
	}

	void Ball::onCollision(Paddle* player1, Paddle* player2)
	{
		handleBoundaryCollision();
		handlePaddleCollision(player1, player2);
		handleOutOfBoundCollision();
	}
}