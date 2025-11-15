#include "Input/InputService.h"
#include "Render/BackgroundRender.h"
#include <Constants/Direction.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
using namespace std;

// calcualte time
float calculateDeltaTime(sf::Clock& clock) {
	sf::Time deltaTime = clock.restart();
	return deltaTime.asSeconds();
}

int main()
{

	sf::Texture mountainTexture;
	mountainTexture.loadFromFile("../Assets/Background/MountainView.png");
	mountainTexture.setRepeated(true);
	sf::Sprite mountainSprite(mountainTexture);

	sf::Texture forestTexture;
	forestTexture.loadFromFile("../Assets/Background/Forest.png");
	forestTexture.setRepeated(true);
	sf::Sprite forestSprite(forestTexture);


	//Render::BackgroundRender backgroundRender;
	Render::BackgroundRender backgroundRender;
	backgroundRender.addLayer(mountainSprite);
	backgroundRender.addLayer(forestSprite);


	//Input service 
	Input::InputService inputService;

	// create the window
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Hello SFML");

	const int FRAME_RATE = 60;
	window.setFramerateLimit(FRAME_RATE);
	sf::Clock clock;

	while (window.isOpen())
	{
		float dt = calculateDeltaTime(clock);
		const Render::BackgroundRenderContext l_ctx{ 100.0f, dt, Direction::Horizontal::Left };
		const Render::BackgroundRenderContext r_ctx{ 100.0f, dt, Direction::Horizontal::Right };
		auto moveLeft = [&]() {
			cout << "Move Left" << endl;
			backgroundRender.update(l_ctx);
			};
		auto moveRight = [&]() {
			cout << "Move Right" << endl;

			backgroundRender.update(r_ctx);
			};

		inputService.registerAction(sf::Keyboard::Key::Left, moveLeft);
		inputService.registerAction(sf::Keyboard::Key::Right, moveRight);


		// window managment 
		while (const std::optional event = window.pollEvent())
		{
			// Request for closing the window
			if (event->is<sf::Event::Closed>())
				window.close();
			if (event->is<sf::Event::Resized>()) {
				backgroundRender.resize(window);
			}
			if (event->is<sf::Event::KeyPressed>()) {
				const sf::Event::KeyPressed* keyEvent = event->getIf<sf::Event::KeyPressed>();
				inputService.update(keyEvent->code);
			}
		}

		// Calculate delta time at the beginning of the frame
		window.clear(sf::Color::Black);
		backgroundRender.render(window);
		window.display();
	}
}