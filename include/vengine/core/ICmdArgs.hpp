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
/// @brief command arguments interface

#pragma once

struct ICmdArgs
{
	///
	virtual int GetCount() const = 0;
	
	///
	virtual const char *GetByIndex(int anIndex) const = 0;
	
	///
	virtual const char *ToString() const = 0;
};