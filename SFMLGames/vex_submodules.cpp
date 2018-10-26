#include "vex_submodules.h"
#include <iostream>

const int SIM_SCALE = 5;

void pollEvents(sf::Window *window)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				window->close();
			}
			break;
		case sf::Event::JoystickButtonPressed:
			std::cout << "Joystick Button: " << event.joystickButton.button << std::endl;
			break;
		default:
			break;
		}
	}

}

vex::lcd::lcd(int x, int y, int width, int height, const char* title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	window->setPosition(sf::Vector2i(x, y));
	window->setVerticalSyncEnabled(true);
}

void vex::lcd::drawRectangle(int x, int y, int width, int height, const vex::color &color)
{
	sf::RectangleShape rect(sf::Vector2f((float)width * SIM_SCALE, (float)height * SIM_SCALE));
	rect.setPosition(sf::Vector2f((float)x * SIM_SCALE, (float)y * SIM_SCALE));
	rect.setFillColor(color.underlying);
	window->draw(rect);
}

bool vex::lcd::update()
{
	if (window->isOpen())
	{
		pollEvents(window);
		return true;
	}
	return false;
}

void vex::lcd::clearScreen(const vex::color &color)
{
	window->clear(color.underlying);
}

void vex::lcd::render()
{
	window->display();
}

void vex::lcd::printAt(int32_t x, int32_t y, const char *format, ...)
{

}

void vex::button::pressed(void(*callback)(void))
{

}