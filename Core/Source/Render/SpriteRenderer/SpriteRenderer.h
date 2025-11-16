#pragma once
#include "Render/Renderer.h"
#include <Model/Context/RenderContext.h>
namespace Render {
	class SpriteRenderer :Renderer
	{
	public:
		SpriteRenderer() = default;
		~SpriteRenderer() = default;
		void render(const Render::RenderContext& ctx) override;
	};
}