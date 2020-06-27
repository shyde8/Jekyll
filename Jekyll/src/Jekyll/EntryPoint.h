#pragma once

extern Jekyll::Application* Jekyll::CreateApplication();

int main()
{
	auto app = Jekyll::CreateApplication();
	app->Run();
	delete app;


	return 0;
}