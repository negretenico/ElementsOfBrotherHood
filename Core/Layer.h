#pragma once
#include "PhaseContext.h"
namespace Layer {
	class Layer
	{
	public:
		virtual ~Layer() = default;
		virtual void run(Phase:: PhaseContext& ctx) = 0;
	};
}