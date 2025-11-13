#pragma once
#include <map>
#include <functional>
#include "SFML/Graphics.hpp"
namespace Event {
	class EventBus
	{
	public:
		void subscribe(const sf::Event& event, const std::function<void()>& callback);
		void publish(const sf::Event& event);
	private: 
		std::map<sf::Event, std::function<void()>> eventMap;
	};
}