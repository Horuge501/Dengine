#pragma once

#ifdef DENJI_PLATFORM_WINDOWS
	#ifdef DENJI_BUILD_DLL
		#define DENJI_API __declspec(dllexport)
	#else
		#define DENJI_API __declspec(dllexport)
	#endif
#else
	#error Only supports Windows
#endif

#define BIT(x) (1 << x)