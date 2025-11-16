#pragma once
#include "Model/Sprite/Behavior.h"
#include "Model/Sprite/SpriteProps.h"
#include <memory>
#include <mutex>
#include <vector>
namespace Entity {
	class SpriteEntity
	{
	private:
		std::vector<std::unique_ptr<Sprite::Behavior>> behaviors;
		Sprite::SpriteProps& sprite;
		std::mutex lock;
	public:
		SpriteEntity(Sprite::SpriteProps& sprite) : sprite(sprite) {};
		void update(float dt);
		void addBehavior(std::unique_ptr<Sprite::Behavior> behavior);
		Sprite::SpriteProps getProps() const;
	};
}