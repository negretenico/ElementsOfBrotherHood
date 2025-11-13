#include "EventRegistry.h"
#include "mutex"
namespace Registry
{
	template<typename Key>
	void EventRegistry<Key>::registerEvent(Key key, EventCallback callback)
	{
		std::lock_guard<std::mutex> guard(registryMutex);
		// protect our critical section if other futures jobs try to add new callbacks
		// mutex is aquired and released once we leave this scope
		eventMap.insert({ key,callback });
	}
	template<typename Key>
	void EventRegistry<Key>::triggerEvent(Key k)
	{
		// create an empty callback
		EventCallback callback; 
		{
			//protect if many are trying to access the map while a wrie is going on 
			std::lock_guard<std::mutex> guard(registryMutex);
			auto it = eventMap.find(k);
			if (it == eventMap.end()) return;
			callback = it->second;
		}
		//execute the callback
		callback();
	}
}