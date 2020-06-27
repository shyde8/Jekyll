#pragma once

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


