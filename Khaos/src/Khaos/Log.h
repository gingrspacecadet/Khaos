#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Khaos {

	class KHAOS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

};

// Core log macros
#define KH_CORE_TRACE(...) ::Khaos::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KH_CORE_INFO(...)  ::Khaos::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KH_CORE_WARN(...)  ::Khaos::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KH_CORE_ERROR(...) ::Khaos::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KH_CORE_FATAL(...) ::Khaos::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define KH_TRACE(...)      ::Khaos::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KH_WARN(...)       ::Khaos::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KH_INFO(...)       ::Khaos::Log::GetClientLogger()->info(__VA_ARGS__)
#define KH_ERROR(...)      ::Khaos::Log::GetClientLogger()->error(__VA_ARGS__)
#define KH_FATAL(...)      ::Khaos::Log::GetClientLogger()->fatal(__VA_ARGS__)