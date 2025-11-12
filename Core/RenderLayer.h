#pragma once
#include "Layer.h"
#include "Service.h"
namespace Layer {
	class RenderLayer : public Layer {
	public:
		explicit RenderLayer(Service::Service& service)
			: renderService(service) {
		}
		void run(Phase::PhaseContext& ctx) override;
		virtual void onResize(int width, int height) {}
	private:
		Service::Service& renderService;
	};
};
