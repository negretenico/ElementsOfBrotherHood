#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include <functional>
#include <iostream>
#include <mutex>
namespace Input {
	typedef std::function<void()> InputAction;
	class InputService
	{
	public:
		void update(const sf::Keyboard::Key& pressedKey);
		void registerAction(sf::Keyboard::Key key, InputAction action);

	private:
		std::map<sf::Keyboard::Key, InputAction> keyActions;
		std::mutex lock;
	};
}