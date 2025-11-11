#paragma once
#include "Phase/Phase.hpp"
namespace Layer {
	class Layer {
		virtual ~Layer() = default;
		virtual void run(PhaseContext& ctx) = 0;
	};
}