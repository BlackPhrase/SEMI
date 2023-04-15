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
/// @brief file handle interface

#pragma once

struct IFile
{
	///
	virtual void Write(const void *apData, int anSize) = 0;
	
	///
	virtual void Read(void *apData, int anSize) const = 0;
	
	///
	virtual const char *GetFullPath() const = 0;
	
	///
	virtual const char *GetName() const = 0;
	
	///
	virtual const char *GetExt() const = 0;
	
	///
	virtual unsigned int GetSize() const = 0; // TODO: probably should be long
};