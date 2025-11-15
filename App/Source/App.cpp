#include "SFML/Graphics.hpp"
#include <iostream>
#include "Core/Core.h"
using namespace std;

// calcualte time
float calculateDeltaTime(sf::Clock& clock) {
	sf::Time deltaTime = clock.restart();
	return deltaTime.asSeconds();
}

int main()
{
	Core::Core c;
	c.Initialize();

	// create the window
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Hello SFML");
	// handle framerate

	window.setFramerateLimit(60);
	sf::Clock clock;

	while(window.isOpen())
	{
		// window managment 
		while (const std::optional event = window.pollEvent())
		{
			// Request for closing the window
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		
		// Calculate delta time at the beginning of the frame
		float dt = calculateDeltaTime(clock);
		window.clear(sf::Color::Black);
		window.display();
	}
}