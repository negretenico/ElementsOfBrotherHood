#include "Core/Core.h"
#include "SFML/Graphics.hpp"
int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Hello SFML");
	while(window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			// Request for closing the window
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		window.clear(sf::Color::Black);
		window.display();
	}
	Core::PrintHelloWorld();
}