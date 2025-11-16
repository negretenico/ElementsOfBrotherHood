#include "SpriteRenderer.h"
#include <Model/Context/RenderContext.h>
#include <SFML/Graphics/Sprite.hpp>

namespace Render
{
	void SpriteRenderer::render(const Render::RenderContext& ctx)
	{
		// Implementation of sprite rendering logic goes here
		for (const auto* spriteProps : ctx.sprites)
		{
			sf::Sprite sprite = spriteProps->toSFMLSprite();
			ctx.window.draw(sprite);
		}
	}
}