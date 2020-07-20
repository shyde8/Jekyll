// TODO
// rather than numeric values, for the EventCategory enum do we want to do some sort of bitwise shift/mask ???

#pragma once

#include <string>

namespace Jekyll
{
	enum class EventType 
	{
		None = 0,
	};

	enum class EventCategory
	{
		None = 0,
	};


	class _declspec(dllexport) Event
	{
	public:
		//virtual const std::string GetEventName();
		//const EventType GetEventType() { return eventType; }
		//const EventCategory GetEventCategory() { return eventCategory; }

		//virtual ~Event();

	private:
		Event(); //base event class should never be instantiated

		EventType eventType;
		EventCategory eventCategory;
		bool handled = false;
	};
}