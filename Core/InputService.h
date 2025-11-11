#pragma 
#include "Service.h"
#include "SFML/Graphics.hpp"
#include <map>
#include <functional>
#include <iostream>

namespace Service {

    class InputService : public Service {
    public:
        void update(Phase::PhaseContext& ctx) override;

    private:
        std::map<sf::Keyboard::Key, std::function<void()>> keyActions = {
            {sf::Keyboard::Key::Left, []() {
                std::cout << "Left key pressed\n";
            }},
            {sf::Keyboard::Key::Right, []() {
                std::cout << "Right key pressed\n";
            }},
            {sf::Keyboard::Key::Up, []() {
                std::cout << "Up key pressed\n";
            }},
            {sf::Keyboard::Key::Down, []() {
                std::cout << "Down key pressed\n";
            }},
            {sf::Keyboard::Key::Escape, []() {
                std::cout << "Escape pressed (pause?)\n";
            }}
        };

    };
}
