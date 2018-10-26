#include "vex_sim.h"
#include <thread>
#include <iostream>

const float SIM_SCALE = 2;

void jbc(vex::controller Controller, sf::Event event)
{
	int button = event.joystickButton.button;
	if (button == 0 && Controller.ButtonA.pressedCallback != nullptr)
	{
		Controller.ButtonA.pressedCallback();
	}
	else if (button == 1 && Controller.ButtonB.pressedCallback != nullptr)
	{
		Controller.ButtonB.pressedCallback();
	}
	else if (button == 2 && Controller.ButtonX.pressedCallback != nullptr)
	{
		Controller.ButtonX.pressedCallback();
	}
	else if (button == 3 && Controller.ButtonY.pressedCallback != nullptr)
	{
		Controller.ButtonY.pressedCallback();
	}
}

vex::brain::brain() : Screen(100, 100, 740, 480, "Vex Brain")
{

}

vex::controller::controller() // : Screen(950, 250, 500, 330, "Vex Controller")
{
	this->joystickButtonCallback = jbc;
}

void vex::task::sleep(uint32_t time)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

vex::lcd::lcd(int x, int y, int width, int height, const char* title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	window->setPosition(sf::Vector2i(x, y));
	//window->setVerticalSyncEnabled(true);
}

void vex::lcd::drawRectangle(int x, int y, int width, int height, const vex::color &color)
{
	sf::RectangleShape rect(sf::Vector2f((float)width * SIM_SCALE, (float)height * SIM_SCALE));
	rect.setPosition(sf::Vector2f((float)x * SIM_SCALE, (float)y * SIM_SCALE));
	rect.setFillColor(color.underlying);
	window->draw(rect);
}

bool vex::lcd::update(vex::controller Controller)
{
	if (window->isOpen())
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
				if (Controller.joystickButtonCallback != nullptr)
					Controller.joystickButtonCallback(Controller, event);
				break;
			case sf::Event::JoystickMoved:
				if (Controller.joystickAxisCallback != nullptr)
					Controller.joystickAxisCallback(Controller, event);
				break;
			default:
				break;
			}
		}
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
	this->pressedCallback = callback;
}