#include "InputService.h"
#include <mutex>
namespace Input
{
	void InputService::update(const sf::Keyboard::Key& pressedKey)
	{
		auto actionIt = keyActions.find(pressedKey);
		if (actionIt == keyActions.end()) return;
		actionIt->second(); // Call the associated 
	}
	void InputService::registerAction(sf::Keyboard::Key key, InputAction action)
	{
		std::lock_guard<std::mutex> guard(lock);
		keyActions.insert({ key,action });
	}
}