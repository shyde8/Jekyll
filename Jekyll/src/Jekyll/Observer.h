#pragma once

namespace Jekyll
{
	class _declspec(dllexport) Observer
	{
	public:
		// Observers are responsible for unregistering from any subjects they're listening to, in the event that the Observer is about to be destroyed //
		// each time we register an Observer with a Broadcaster, a corresponding RemoveObserver() call should be added to the destructor //
		virtual  ~Observer();

		virtual void OnBroadcast(const Entity& e, Event event) = 0;
	};
}