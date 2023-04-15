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
/// @brief config interface

#pragma once

struct IConfig
{
	///
	virtual void SetString(const char *asKey, const char *asValue) = 0;
	//virtual void SetString(const char *asSection, const char *asKey, const char *asValue) = 0;
	
	///
	virtual const char *GetString(const char *asKey) const = 0;
};