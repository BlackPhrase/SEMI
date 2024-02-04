/*
 * This file is part of V-Engine
 *
 * Copyright 2024 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#pragma once

struct IVEngine
{
	struct InitProps
	{
		
	};
	
	///
	virtual bool Init(const InitProps &aInitProps) = 0;
};