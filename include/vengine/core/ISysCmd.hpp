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

#pragma once

struct ICmdArgs;

struct ISysCmd
{
	///
	virtual void Exec(const ICmdArgs &aArgs) = 0;
	
	///
	virtual const char *GetName() const = 0;
	
	///
	virtual const char *GetDesc() const = 0;
};