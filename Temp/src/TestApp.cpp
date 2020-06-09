#include <Jekyll.h>

class Temp : public Jekyll::Application
{
public:
	Temp() {};
	~Temp() {};
};

Jekyll::Application* Jekyll::CreateApplication()
{
	return new Temp();
}
