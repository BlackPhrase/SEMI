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
#include <string_view>
#include <vector>
#include <list>

#include "PlatformTypes.hpp"

#define C_EXPORT extern "C" EXPORT_FUNC

using tString = std::string;

using tStringView = std::string_view;

using tStringVec = std::vector<tString>;
using tStringList = std::list<tString>;