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

#ifdef DENJI_ENABLE_ASSERTS
	#define DENJI_ASSERT(x, ...) {if(!(x)){ERROR("Assertion Failed: {0}", __VA_ARGS); __debugbreak();}}
	#define DENJI_CORE_ASSERT(x, ...) {if(!(x)){ERROR("Assertion Failed: {0}", __VA_ARGS); __debugbreak();")}}
#else
	#define DENJI_ASSERT(x, ...)
	#define DENJI_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)