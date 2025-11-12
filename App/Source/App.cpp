#include "Core/Core.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Phase.h"
#include "Layer.h"
#include "Service.h"
#include "InputLayer.h"
#include "InputService.h"
using namespace std;

// calcualte time
float calculateDeltaTime(sf::Clock& clock) {
	sf::Time deltaTime = clock.restart();
	return deltaTime.asSeconds();
}

int main()
{

	// create the window
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Hello SFML");
	// handle framerate

	window.setFramerateLimit(60);
	sf::Clock clock;

	std::vector<sf::Event> frameEvents;

	//Phase Definitions
	Phase::Phase preupdatePhase;
	Phase::Phase renderPhase;

	//Service definitions 
	Service::InputService inputService;

	//Layer definitions
	auto inputLayer = std::make_unique<Layer::InputLayer>(inputService);
	preupdatePhase.addLayer(std::move(inputLayer));


	while(window.isOpen())
	{
		/*
		*   preUpdatePhase.update(dt);   // InputLayer, etc.
    updatePhase.update(dt);      // EntityLayer, AI, Physics
    postUpdatePhase.update(dt);  // MusicLayer, AnalyticsLayer
    renderPhase.update(dt);      // RenderLayer
		*/
		frameEvents.clear(); 

		// window managment 
		while (const std::optional event = window.pollEvent())
		{
			frameEvents.push_back(*event);
			// Request for closing the window
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		
		// Calculate delta time at the beginning of the frame
		float dt = calculateDeltaTime(clock);
		Phase::PhaseContext ctx{ window, dt, true, frameEvents };
		preupdatePhase.run(ctx); // hanle inputs
		window.clear(sf::Color::Black);
		window.display();
	}
}