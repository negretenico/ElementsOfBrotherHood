#include "MoveableSprite.h"
#include <iostream>
namespace Sprite {
	void Moveable::update(float dt) {
		std::cout << "Hi Nico" << std::endl;
		sprite->position += velocity * dt;
	}
}