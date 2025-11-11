#pragma once
#include <iostream>
#include "Layer.h"
#include "PhaseContext.h"
namespace Layer {
    class Layer;
};
namespace Phase {
    class Phase {

    public:
        void addLayer(std::unique_ptr<Layer::Layer> layer);
        void run(PhaseContext& ctx);

    private:
        std::vector<std::unique_ptr<Layer::Layer>> layers;
    };

}
