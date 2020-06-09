#pragma once

#include "Core.h"

namespace Jekyll
{
	class _declspec(dllexport) Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}


