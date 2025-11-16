#pragma once
#include "Model/Sprite/Behavior.h"
#include "Model/Sprite/SpriteProps.h"
namespace Sprite {
	class Animated :public Behavior
	{
		SpriteProps* sprite;

		int framesPerRow;
		float frameDuration;
		float timer = 0;
		int currentFrame = 0;
	public:
		Animated(SpriteProps* props, int framesPerRow, float frameDuration) : sprite(props), framesPerRow(framesPerRow), frameDuration(frameDuration) {};
		void update(float dt) override;
	};
}