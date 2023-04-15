/*
 * This file is part of V-Engine
 *
 * Copyright 2018, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file
/// @brief platform-specific types & definitions

#pragma once

// To prevent people from using platform-specific headers directly
#define PLATFORM_SELECTOR

#ifdef _WIN32
	#include "platform/PlatformWindows.hpp"
#elif __linux__
	#include "platform/PlatformLinux.hpp"
#elif __APPLE__
	#include "platform/PlatformApple.hpp"
#else
	#error "Unsupported platform! (Or you're doing something wrong)"
#endif

#undef PLATFORM_SELECTOR