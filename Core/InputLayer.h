#pragma 
#include "Layer.h"
#include "Service.h"

namespace Layer {

    class InputLayer : public Layer {
    public:
        explicit InputLayer(Service::Service& service)
            : inputService(service) {
        }

        void run(Phase::PhaseContext& ctx) override;

    private:
        Service::Service& inputService;
    };

} 
