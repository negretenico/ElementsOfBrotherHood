#pragma once
#include "SFML/Graphics.hpp"

namespace Phase {
    struct PhaseContext {
        sf::RenderWindow& window;
        float dt;
        bool running = true;
        std::vector<sf::Event> events; 
    };
}