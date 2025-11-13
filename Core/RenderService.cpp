#include "RenderService.h"
#include "Service.h"
namespace Service {
	void RenderService::update(Phase::PhaseContext& ctx)
	{
		// Rendering logic would go here
		ctx.window.clear(sf::Color::Black);
		ctx.window.display();
	}
}