#include "Core/Core.h"
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;
// input hanlding
void handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		// left key is pressed: move our character
		cout << "Left key pressed" << endl;
	}
}

// calcualte time
float calculateDeltaTime(sf::Clock clock) {
	sf::Time deltaTime = clock.restart();
	return deltaTime.asSeconds();
}

int main()
{
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
		handleInput();
		window.clear(sf::Color::Black);
		window.display();
	}
}