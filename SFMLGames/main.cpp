#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::Window window(sf::VideoMode(1080, 720, sf::Style::Default), "SFML Games");
	window.setVerticalSyncEnabled(true);
	window.setTitle("Snake");
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
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

	return 0;
}