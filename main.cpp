#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::Window window;
    window.create(sf::VideoMode(800, 600), "SFML Games");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}