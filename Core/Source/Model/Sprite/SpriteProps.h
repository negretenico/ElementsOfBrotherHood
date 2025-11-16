#pragma once
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
namespace Sprite {
	struct SpriteProps {
		std::shared_ptr<sf::Texture> texture = nullptr;
		sf::Vector2f position{};
		sf::IntRect frame{};
		float rotation = 0.f;
		sf::Vector2f scale{ 1.f, 1.f };
		sf::Sprite toSFMLSprite() const {
			//TODO: Handle null texture case
			sf::Sprite sprite(*texture);
			sprite.setPosition(position);
			sprite.setTextureRect(frame);
			sf::Angle angle = sf::degrees(rotation);
			sprite.setRotation(angle);
			sprite.setScale(scale);
			return sprite;
		}
	};
}