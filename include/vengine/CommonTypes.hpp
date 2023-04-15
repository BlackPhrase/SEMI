/*
 * This file is part of V-Engine
 *
 * Copyright 2017-2018, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#pragma once

#include <string>

#include "PlatformTypes.hpp"

#ifdef _WIN32
	#define EXPORT_FUNC [[dllexport]]
#elif __linux__
	#define EXPORT_FUNC [[visibility("default")]]
#else
	#error "Unsupported compiler!"
#endif

#define C_EXPORT extern "C" EXPORT_FUNC

using tString = std::string;