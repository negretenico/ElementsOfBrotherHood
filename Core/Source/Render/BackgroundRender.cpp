#include "BackgroundRender.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
namespace Render
{
	void BackgroundRender::render(sf::RenderWindow& window)
	{
		for (auto& sprite : sprites)
		{
			window.draw(sprite);
		}
	};
	void BackgroundRender::addLayer(sf::Sprite& layer)
	{
		sprites.push_back(layer);
	}
	void BackgroundRender::update(const BackgroundRenderContext& ctx)
	{
		const sf::Vector2 velocity(ctx.dt * ctx.scrollSpeed * static_cast<int>(ctx.dir), 0.0f);

		for (auto& sprite : sprites)
		{
			sprite.move(velocity);
		}
	}
	void BackgroundRender::resize(sf::RenderWindow& window)
	{
		sf::Vector2u windowSize = window.getSize();

		for (auto& sprite : sprites)
		{
			sf::Vector2f bounds = sprite.getLocalBounds().size;
			float scaleX = static_cast<float>(windowSize.x) / bounds.x;
			float scaleY = static_cast<float>(windowSize.y) / bounds.y;
			float scale = std::max(scaleX, scaleY);
			sprite.setScale({ scale, scale });

			// Initial centering
			sprite.setPosition(
				{ (windowSize.x - bounds.x * scale) / 2.0f,
				(windowSize.y - bounds.y * scale) / 2.0f });
		}

		lastWindowSize = windowSize;
	}
}