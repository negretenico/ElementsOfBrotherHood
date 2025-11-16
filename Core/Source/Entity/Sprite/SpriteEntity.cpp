#include "Model/Sprite/Behavior.h"
#include "SpriteEntity.h"
#include <Model/Sprite/SpriteProps.h>
#include <memory>
#include <mutex>
#include <utility>
#include <vector>
namespace Entity
{
	void SpriteEntity::addBehavior(std::unique_ptr<Sprite::Behavior> behavior) {
		std::lock_guard<std::mutex> guard(lock);
		behaviors.push_back(std::move(behavior));
	}
	void SpriteEntity::update(float dt) {
		std::lock_guard<std::mutex> guard(lock);
		for (const auto& behavior : behaviors) {
			behavior->update(dt);
		}
	}
	Sprite::SpriteProps SpriteEntity::getProps() const {
		return sprite;
	}
}