#pragma once
#include "Service.h"
#include "ResizeContext.h"
namespace Service {
	class RenderService : public Service {
	public:
		void update(Phase::PhaseContext& ctx) override;
		void resize(const Render::ResizeContext& ctx);
	};
}