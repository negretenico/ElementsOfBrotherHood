#pragma once
#include <Model/Sprite/SpriteProps.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

namespace Render {
	struct RenderContext {
		sf::RenderWindow& window;
		// hold pointers to live SpriteProps so render reflects updates
		const std::vector< Sprite::SpriteProps* >& sprites;
	};
}