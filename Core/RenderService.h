#pragma once
#include "Service.h"
namespace Service {
	class RenderService : public Service {
	public:
		void update(Phase::PhaseContext& ctx) override;
	};
}