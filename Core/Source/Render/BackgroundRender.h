#pragma once
#include "Constants/Direction.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
namespace Render
{
	struct BackgroundRenderContext {
		float scrollSpeed;
		float dt;
		Direction::Horizontal dir;
	};
	class BackgroundRender
	{
	public:
		void render(sf::RenderWindow& window);
		BackgroundRender() {};
		void addLayer(sf::Sprite& layer);
		void update(const BackgroundRenderContext& ctx);
		void resize(sf::RenderWindow& window);
	private:
		std::vector< sf::Sprite> sprites;
		sf::Vector2u lastWindowSize;
	};
}