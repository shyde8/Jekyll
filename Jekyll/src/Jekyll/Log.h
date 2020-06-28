// TODO //
// 1. write messages to alternative locations (VS, file. in-game console)
// 2. specify location in window to write messages
// 3. LogLevel enum ???
// 4. additional log categories (i.e. Fatal)
// 5. add argument parameters to the Log functions
// 6. ability to take in inputs aside from string, similarly to how std::cout works (override << )
// 7. do we need to worry about clearing old logs / flushing buffers / resetting state ???
// 8. store actual log message in std::string, or another structure ???
// 9. stacktrace / timestamps
// 10. cleanup when program ends
// 11. disable = operator

#pragma once
#include <string>
#include <iostream>

#define __LOCATION__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#if JKL_LOGLEVEL >= 2
	#define LOG_INFORMATION(message) Jekyll::Log::Get().LogInformation(__LOCATION__, __LINE__, message)
#else
	#define LOG_INFORMATION(message)
#endif

#if JKL_LOGLEVEL >= 1
	#define LOG_WARNING(message) Jekyll::Log::Get().LogWarning(__LOCATION__, __LINE__, message)
#else
	#define LOG_WARNING(message)
#endif

#if JKL_LOGLEVEL >= 0
	#define LOG_ERROR(message) Jekyll::Log::Get().LogError(__LOCATION__, __LINE__, message)
#else
	#define LOG_ERROR(message)
#endif

namespace Jekyll
{
	class _declspec(dllexport) Log
	{
	public:
		Log(const Log&) = delete;

		static Log& Get()
		{
			static Log instance;
			return instance;
		}

		void LogError(const std::string& location, int line, const std::string& message);
		void LogWarning(const std::string& location, int line, const std::string& message);
		void LogInformation(const std::string& location, int line, const std::string& message);
	
	private:
		Log() {};
	};
}