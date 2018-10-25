#include "vex_sim.h"
#include <iostream>

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

vex::lcd::lcd()
{
	window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Vex Simulator");
	window->setVerticalSyncEnabled(true);
	window->setTitle("Snake");
}

void vex::lcd::drawRectangle(int x, int y, int width, int height, vex::color color)
{
	sf::RectangleShape rect(sf::Vector2f((float)width, (float)height));
	rect.setPosition(sf::Vector2f((float)x, (float)y));
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

void vex::lcd::clearScreen(vex::color color)
{
	window->clear(color.underlying);
}

void vex::lcd::render()
{
	window->display();
}

vex::color::color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) : underlying(sf::Color(r, g, b, a))
{

}

const vex::color vex::color::black(0, 0, 0);
const vex::color vex::color::white(255, 255, 255);
const vex::color vex::color::red(255, 0, 0);
const vex::color vex::color::green(0, 255, 0);
const vex::color vex::color::blue(0, 0, 255);
const vex::color vex::color::yellow(255, 255, 0);
const vex::color vex::color::magenta(255, 0, 255);
const vex::color vex::color::cyan(0, 255, 255);
const vex::color vex::color::transparent(0, 0, 0, 0);