#pragma once
#include <map>
#include <functional>
#include "SFML/Graphics.hpp"
namespace Event {
	class EventBus
	{
	public:
		void subscribe(const sf::Event& event, const std::function<void()>& callback) {
			eventMap[event] = callback;
		}
		void publish(const sf::Event& event) {
			auto it = eventMap.find(event);
			if (it == eventMap.end()) return;
			it->second;
		}
	private: 
		std::map<sf::Event, std::function<void()>> eventMap;
	};
}