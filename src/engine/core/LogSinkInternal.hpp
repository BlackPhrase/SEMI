/*
 * This file is part of V-Engine
 *
 * Copyright 2018-2019, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file
/// @brief internal log sink (temp?)

#pragma once

#include <iostream>

#include "core/ILogger.hpp"

class CLogSinkInternal final : public ILogSink
{
public:
	CLogSinkInternal() = default;
	~CLogSinkInternal() = default;
	
	void OnMessage(const char *asMsg) override
	{
		std::cout << asMsg << std::endl;
	};
};