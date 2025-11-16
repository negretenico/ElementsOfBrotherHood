#include "Entity/Sprite/SpriteEntity.h"
#include "Input/InputService.h"
#include "Model/Sprite/Moveable/MoveableSprite.h"
#include "Render/SpriteRenderer/SpriteRenderer.h"
#include <Model/Context/RenderContext.h>
#include <Model/Sprite/SpriteProps.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <memory>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// calcualte time
float calculateDeltaTime(sf::Clock& clock) {
	sf::Time deltaTime = clock.restart();
	return deltaTime.asSeconds();
}

Sprite::SpriteProps createProps(string path, sf::Vector2f position = { 0.f, 0.f }, sf::IntRect frameRect = { { 0, 0 }, { 800, 600 } }, sf::Vector2f scale = { 1.f, 1.f }) {
	// Entit set up 
	Sprite::SpriteProps props;
	props.position = position;
	props.scale = scale;
	props.frame = frameRect;
	// this needs to be a shared pointer so we don't have a dangling pointer when the function exits
	// silly slut :( 
	auto txture = std::make_shared<sf::Texture>();
	txture->loadFromFile(path);
	txture->setRepeated(true);
	props.texture = txture;
	return props;
}

int main()
{

	//Entity Setup
	//if we had a copy construcotr in our SpriteProps we could pass this in directly instead of creating a new variable
	Sprite::SpriteProps mtnProps = createProps("../Assets/Background/MountainView.png");
	Entity::SpriteEntity moutain(mtnProps);
	auto mtnMove = std::make_unique < Sprite::Moveable >(mtnProps, sf::Vector2f({ 10000.f,0.f }));
	moutain.addBehavior(std::move(mtnMove));

	Sprite::SpriteProps frstProps = createProps("../Assets/Background/Forest.png");
	Entity::SpriteEntity forest(frstProps);


	//Input service 
	Input::InputService inputService;

	// create the window
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Hello SFML");


	//  Renderers setup
	//TODO: can we get away with using a std::array so we dont have to dynamicly allocate memory here?
	//TODO: look into lifetimes, why can't we just pass this straight in
	std::vector<Sprite::SpriteProps*> sprites{ &mtnProps, &frstProps };
	Render::RenderContext renderContext{ window, sprites };
	Render::SpriteRenderer backgroundRender;



	const int FRAME_RATE = 60;
	window.setFramerateLimit(FRAME_RATE);
	sf::Clock clock;

	// register input action once, use a mutable dt reference updated each frame
	float currentDt = 0.f;
	auto mtnUpdateFunc = [&moutain, &currentDt]() {
		moutain.update(currentDt);
	};
	inputService.registerAction(sf::Keyboard::Key::Right, mtnUpdateFunc);

	while (window.isOpen())
	{
		currentDt = calculateDeltaTime(clock);

		// window managment 
		while (const std::optional event = window.pollEvent())
		{
			// Request for closing the window
			if (event->is<sf::Event::Closed>())
				window.close();
			if (event->is<sf::Event::KeyPressed>()) {
				const sf::Event::KeyPressed* keyEvent = event->getIf<sf::Event::KeyPressed>();
				inputService.update(keyEvent->code);
			}
		}

		// Calculate delta time at the beginning of the frame
		window.clear(sf::Color::Black);
		backgroundRender.render(renderContext);
		window.display();
	}
}