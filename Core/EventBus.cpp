#include "EventBus.h"
namespace Event {
	void EventBus::publish(const sf::Event& event) {
		auto it = eventMap.find(event);
		if (it == eventMap.end()) return;
		it->second;
	}
	void EventBus::subscribe(const sf::Event& event, const std::function<void()>& callback)
	{
		eventMap[event] = callback;
	}
}