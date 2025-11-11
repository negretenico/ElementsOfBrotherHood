#include "Service.h"
#include "SFML/Graphics.hpp"
#include <functional>
#include <map>
#include <iostream>
#include "InputService.h"
namespace Service {
    void InputService::update(Phase::PhaseContext& ctx)
    {
        for (auto& event : ctx.events){
            // we could probably use a walrus operator here; but I prefer this way for clarity
            if (!event.is<sf::Event::KeyPressed>())continue;
            const sf::Event::KeyPressed* keyEvent = event.getIf<sf::Event::KeyPressed>();
             auto it = keyActions.find(keyEvent->code);
            if (it == keyActions.end()) continue;
            it->second();
        }
	}
}