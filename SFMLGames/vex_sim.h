#pragma once
#include <SFML/Graphics.hpp>
#include "vex_types.h"

#define VEX_SIMULATOR_MODE true
#define ACTIVE Brain.Screen.update()

void pollEvents(sf::Window* window);

namespace vex
{
	class lcd
	{
	private:
		sf::RenderWindow *window = nullptr;
	public:
		lcd();
		void drawRectangle(int x, int y, int width, int height, vex::color color);
		bool update();
		void clearScreen(vex::color color);
		void render();
	};

	class brain
	{
	public:
		lcd Screen;
	};
}