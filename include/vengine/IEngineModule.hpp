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

/// Main module export
using pfnModuleMain = IEngineModule *(*)(const ICoreEnv &aCoreEnv);
//using pfnModuleInit = int (*)(const ICoreEnv &aCoreEnv);
//using pfnModuleShutdown = void (*)(const ICoreEnv &aCoreEnv);

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
};

struct IEngineModule
{
	///
	//void (*Release)();
	
	///
	//void (*AddRef)();
	
	///
	void *(*GetInterface)(const char *asName, int anVersion);
};

class CEngineModuleWrapper
{
public:
	CEngineModuleWrapper(IEngineModule *apModule) : mpModule(apModule){}
	~CEngineModuleWrapper() = default;
	
	void *GetInterface(const char *asName, int anVersion) const
	{
		return mpModule->GetInterface(asName, anVersion);
	};
	
	/// Templated version of the above method
	template<typename T>
	T *GetInterface(const char *asName, int anVersion) const
	{
		return static_cast<T*>(GetInterface(asName, anVersion));
	};
private:
	IEngineModule *mpModule{nullptr};
};