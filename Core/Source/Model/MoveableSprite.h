#pragma once
#include "SFML/Graphics/Sprite.hpp"
class Sprite {
	class MoveableSprite
	{
	public:
		MoveableSprite();
	private:
		float movementSpeed;
		sf::Sprite sprite;
	};
};