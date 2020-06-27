#include "Log.h"

namespace Jekyll
{
	void Log::LogError(const std::string& location, int line, const std::string& message)
	{
		std::cout << "[ERROR]: " << location << "." << line << " " << message << std::endl;
	}

	void Log::LogWarning(const std::string& location, int line, const std::string& message)
	{
		std::cout << "[WARNING]: " << location << "." << line << " " << message << std::endl;
	}

	void Log::LogInformation(const std::string& location, int line, const std::string& message)
	{
		std::cout << "[INFORMATION]: " << location << "." << line << " " << message << std::endl;
	}
}