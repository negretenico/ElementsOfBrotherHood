#include "Animated.h"
#include <SFML/Graphics/Rect.hpp>
namespace Sprite {
	void Animated::update(float dt) {
		timer += dt;
		if (timer < frameDuration) { return; }
		timer -= frameDuration;
		currentFrame = (currentFrame + 1) % framesPerRow;
		sprite->frame.position = { sprite->frame.position.x * currentFrame, sprite->frame.position.y };
	}
}