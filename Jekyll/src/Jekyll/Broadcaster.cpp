#include "Broadcaster.h"

namespace Jekyll
{
	void Broadcaster::AddObserver(Observer* observer)
	{
		for (Observer* obs : this->_observers)
		{
			if (obs == observer)
			{
				return;
			}
		}

		this->_observers.push_back(observer);
	}

	void Broadcaster::RemoveObserver(Observer* observer)
	{
		std::vector<Observer*>::iterator it;
		it = std::find(this->_observers.begin(), this->_observers.end(), observer);
		if (it != this->_observers.end())
		{
			this->_observers.erase(it);
		}
		else {}
	}

	void Broadcaster::Broadcast(const Entity& entity, Event event)
	{
		for (Observer* obs : this->_observers)
		{
			obs->OnBroadcast(entity, event);
		}
	}
}