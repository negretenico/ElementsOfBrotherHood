#pragma once
#include "Layer.h"
#include "RenderService.h"
namespace Layer {
	class RenderLayer : public Layer {
	public:
		explicit RenderLayer(Service::RenderService& service)
			: renderService(service) {
		}
		void run(Phase::PhaseContext& ctx) override;
	private:
		Service::RenderService& renderService;
	};
};
