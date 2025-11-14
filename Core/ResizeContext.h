#pragma once
#include "SFML/Graphics.hpp"
namespace Render {
	struct ResizeContext {
		sf::RenderWindow& window;
		// no negative widths or heights xD
		unsigned int width;
		unsigned int height;
	};
}