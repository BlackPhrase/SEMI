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
/// @brief console variable interface

#pragma once

// TODO: IConVar
struct ISysVar
{
	///
	virtual const char *GetName() const = 0;
	
	///
	virtual const char *GetDescription() const = 0;
	
	///
	virtual void SetValue(const char *asValue) = 0;
	
	///
	virtual const char *GetValue() const = 0;
	
	///
	virtual const char *GetDefValue() const = 0;
	
	///
	virtual void ResetValue() = 0;
};