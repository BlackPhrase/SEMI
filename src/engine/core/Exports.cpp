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

#include <CommonTypes.hpp>

#include "EngineCore.hpp"

C_EXPORT IEngineCore *GetVEngineCore(int anVersion)
{
	if(anVersion == IEngineCore::Version)
	{
		static CEngineCore EngineCore;
		return &EngineCore;
	};
};