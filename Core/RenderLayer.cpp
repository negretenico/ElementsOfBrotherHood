#include "RenderLayer.h"
#include "Service.h"
namespace Layer {
	void RenderLayer::run(Phase::PhaseContext& ctx) {
		renderService.update(ctx);
	};
}