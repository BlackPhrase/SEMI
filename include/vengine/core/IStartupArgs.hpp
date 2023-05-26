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
/// @brief app startup arguments interface

#pragma once

struct IStartupArgs
{
	/// @param asKey A key name to check for
	/// @return whether or not the specified key is present
	virtual bool Contains(const char *asKey) const = 0;
	
	/// @return keys count
	virtual int GetCount() const = 0;
	
	/// @param asKey A key name to retreive value from
	/// @return value of the specified key (if present)
	virtual const char *Get(const char *asKey) const = 0; // TODO: GetValue?
	
	/// @return all the arguments as a single immutable string
	virtual const char *ToString() const = 0;
};