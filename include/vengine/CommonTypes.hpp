/// @file

#pragma once

#include "PlatformTypes.hpp"

#ifdef _WIN32
	#define EXPORT_FUNC [[dllexport]]
#elif __linux__
	#define EXPORT_FUNC [[visibility("default")]]
#else
	#error "Unsupported compiler!"
#endif

#define C_EXPORT extern "C" EXPORT_FUNC