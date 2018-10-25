#pragma once
#include <SFML/Graphics.hpp>

#define VEX_SIMULATOR_MODE true
#define ACTIVE Brain.Screen.update()

void pollEvents(sf::Window* window);

namespace vex
{
	class color
	{
	public:
		color(sf::Color underlying);
		const sf::Color underlying;
		static const color black;
		static const color white;
		static const color red;
		static const color green;
		static const color blue;
		static const color yellow;
		static const color magenta;
		static const color cyan;
		static const color transparent;
	};

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