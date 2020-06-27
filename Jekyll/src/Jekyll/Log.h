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