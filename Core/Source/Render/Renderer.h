#pragma once
#include "Model/Context/RenderContext.h"
namespace Render {
	class Renderer
	{
	public:
		virtual void render(const Render::RenderContext& ctx) = 0;
	};
}
