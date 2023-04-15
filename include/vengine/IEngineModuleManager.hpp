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
/// @brief engine module manager interface

#pragma once

struct IEngineModule;

struct IEngineModuleManager
{
	///
	virtual bool LoadModule(const char *asName) = 0;
	
	///
	virtual bool UnloadModule(int anIndex) = 0;
	
	///
	virtual bool ReloadModule(int anIndex) = 0;
	
	///
	//virtual IEngineModule *GetModule(int anIndex) const = 0;
	
	///
	virtual void *GetInterface(const char *asName, int anVersion) const = 0;
};