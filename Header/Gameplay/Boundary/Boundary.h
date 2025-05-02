#pragma once
#include "../../SFML/include/SFML/Graphics.hpp"

using namespace sf;

namespace Gameplay {
	class Boundary {
	private:

		RectangleShape topBoundary;
		RectangleShape bottomBoundary;
		RectangleShape leftBoundary;
		RectangleShape rightBoundary;
		RectangleShape centerLine;

		//Horizontal boundary dimensions(top and bottom
		const float horizontal_boundary_width = 1280.0f;
		const float horizontal_boundary_height = 20.0f;

		//Vertical boundary dimensions(left and right)
		const float vertical_boundary_width = 20.0f;
		const float vertical_boundary_height = 720.0f;

		//Top boundary starts at the window's top-left corner
		const float top_position_x = 0.0f;
		const float top_position_y = 0.0f;

		//Bottom Boundary
		const float bottom_position_x = 0.0f;
		const float bottom_position_y = 700.0f;

		//Left boundary also starts at top-left
		const float left_position_x = 0.0f;
		const float left_position_y = 0.0f;

		//right boundary 
		const float right_position_x = 1260.0f;
		const float right_position_y = 0.0f;

		//Boundary colors
		const Color boundary_color = Color::Blue;
		const Color center_line_color = Color::White;

		//center line properties
		const float center_line_width = 10.0f;
		const float center_line_height = 680.0f;

		const float center_line_position_x = 640.0f;
		const float center_line_position_y = 20.0f;

		//create boundaries and the center line
		void createTopBoundary();
		void createBottomBoundary();
		void createLeftBoundary();
		void createRightBoundary();

		void createCenterLine();

	public:
		Boundary();
		void render(RenderWindow* game_window);
	};
}
