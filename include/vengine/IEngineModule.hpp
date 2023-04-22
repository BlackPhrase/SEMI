/*
 * This file is part of V-Engine
 *
 * Copyright 2017-2018, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#pragma once

struct ICoreEnv;
struct IEngineModule;

/// Main module export
using pfnModuleMain = IEngineModule *(*)(const ICoreEnv &aCoreEnv);
//using pfnModuleInit = int (*)(const ICoreEnv &aCoreEnv);
//using pfnModuleShutdown = void (*)(const ICoreEnv &aCoreEnv);

/*
struct SEngineModuleInfo
{
	const char *msName{""};
	const char *msVersion{""};
	const char *msAuthor{""};
};

struct IBaseInterface
{
	///
	//void (*Release)();
	//virtual void Release() = 0;
};
*/

struct IEngineModule
{
	///
	//void (*Release)();
	//virtual void Release() = 0;
	
	///
	//void (*AddRef)();
	//virtual void AddRef() = 0;
	
	///
	virtual bool OnLoad() = 0;
	
	///
	virtual bool OnUnload() = 0;
	
	///
	//virtual bool OnReload() = 0;
	
	///
	//void *(*GetInterface)(const char *asName, int anVersion);
	virtual void *GetInterface(const char *asName, int anVersion) const = 0;
};