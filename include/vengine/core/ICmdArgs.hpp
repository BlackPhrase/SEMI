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
	/// @return all the arguments count
	virtual int GetCount() const = 0;
	
	/// @param anIndex Index of the key
	/// @return the argument at the specified index
	virtual const char *GetAt(int anIndex) const = 0;
	
	/// @return all the arguments as a single immutable string
	virtual const char *ToString() const = 0;
public: // Helpers
	/// @return the name of the cmd
	inline const char *GetCmdName() const {return GetAt(0);}
};