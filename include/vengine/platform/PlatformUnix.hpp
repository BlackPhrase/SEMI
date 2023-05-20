/*
 * This file is part of V-Engine
 *
 * Copyright 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file
/// @brief Unix platform-specific types & definitions

#pragma once

#ifndef PLATFORM_SELECTOR
	#error "You shouldn't use this file directly!"
#endif

#define EXPORT_FUNC [[gnu::visibility("default")]]

/////////////////////////////////////////////////////////////////////