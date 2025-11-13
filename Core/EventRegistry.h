#pragma once
#include <map>
#include <string>
#include <functional>
#include <mutex>

namespace Registry {
	typedef std::function<void()> EventCallback;
	template<typename Key>
	class EventRegistry
	{
		public:
			void registerEvent(Key key, EventCallback callback);
			void triggerEvent(Key k);
	private:
		std::map<Key, EventCallback> eventMap;
		std::mutex registryMutex;
	};
}

