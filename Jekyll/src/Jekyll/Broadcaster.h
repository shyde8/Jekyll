// TODO //

// 1. event system is currently synchronous/blocking; in the future, consider migration to asynchronous event queue

// 2. the current event system is based on the "Observer" pattern, in which an entity will need to derive from the Observer class in order to implement the OnBroadcast() method.  
// Consider removing the Observer class and broadcasting a function pointer to the needed function instead
// With the function pointer approach, there may be complexities with regard to functions requiring different parameters, returning different data types, etc.

// 3. for the internal _observers list, is there a more efficient container we can use instead of vector?

// 4. consider creating an Event which will be broadcasted in the event that the Broadcaster is going to be destroyed, so that the Observers are aware and do any needed cleanup

#pragma once

#include "Events/Event.h"
#include "Log.h"
#include "Entity.h"
#include "Observer.h"
#include <vector>

namespace Jekyll
{
	class _declspec(dllexport) Broadcaster
	{
	public:
		void AddObserver(Observer* observer);
		void RemoveObserver(Observer* observer);

	protected:
		void Broadcast(const Entity& entity, Event event);

	private:
		std::vector<Observer*> _observers;	

	};
}