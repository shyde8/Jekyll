#pragma once

#include <stdio.h>
extern Jekyll::Application* Jekyll::CreateApplication();

int main()
{
	printf("JEKYLL ENGINE");
	auto app = Jekyll::CreateApplication();
	app->Run();
	delete app;


	return 0;
}