#include "Phase.h"

namespace Phase {

    void Phase::addLayer(std::unique_ptr<Layer::Layer> layer) {
        layers.push_back(std::move(layer));
    }

    void Phase::run(PhaseContext& ctx) {
        for (auto& layer : layers) {
            layer->run(ctx); 
        }
    }

} 