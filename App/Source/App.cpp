#include "Core/Core.h"
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;
void handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		// left key is pressed: move our character
		cout << "Left key pressed" << endl;
	}
}

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
		handleInput();
		window.clear(sf::Color::Black);
		window.display();
	}
}