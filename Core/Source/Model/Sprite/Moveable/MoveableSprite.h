#pragma once
#include "Model/Sprite/Behavior.h"
#include "Model/Sprite/SpriteProps.h"
#include <SFML/System/Vector2.hpp>
namespace Sprite {
	class Moveable : public Behavior {
		SpriteProps* sprite;
		sf::Vector2f velocity;
	public:
		// Accept a reference so callers can pass a SpriteProps object directly
		Moveable(SpriteProps& s, sf::Vector2f vel)
			: sprite(&s), velocity(vel) {
		};
		void update(float dt) override;
	};
}