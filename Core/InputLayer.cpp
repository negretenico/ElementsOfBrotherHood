#include "InputLayer.h"
#include <iostream>
#include "Service.h"
using namespace Layer;
namespace Layer {
	void InputLayer::run(Phase::PhaseContext& cxt)  {
		inputService.update(cxt);
	}
}