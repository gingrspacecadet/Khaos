#pragma once

#ifdef KH_PLATFORM_WINDOWS
	#ifdef KH_BUILD_DLL
		#define KHAOS_API __declspec(dllexport)
	#else
		#define KHAOS_API __declspec(dllimport)
	#endif
#else
    #error Khaos only supports Windows!
#endif