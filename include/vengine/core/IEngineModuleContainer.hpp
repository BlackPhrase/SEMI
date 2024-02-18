/*
 * This file is part of V-Engine
 *
 * Copyright 2023-2024 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file
/// @brief engine module container interface

#pragma once

struct IEngineModule;

struct IEngineModuleContainer
{
	///
	virtual bool LoadModule(const char *asName, bool abCritical = false) = 0;
	
	///
	virtual bool UnloadModule(int anIndex) = 0;
	
	///
	virtual bool ReloadModule(int anIndex) = 0;
	
	///
	//virtual IEngineModule *GetModule(int anIndex) const = 0;
	
	///
	virtual void *GetInterface(const char *asName, int anVersion) const = 0;
};