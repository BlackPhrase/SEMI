/*
 * This file is part of V-Engine
 *
 * Copyright 2017-2019, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file
/// @brief module loader - actually used to load modules

#pragma once

#include <konbini/shared_lib.hpp>

#include <CommonTypes.hpp>
#include <IEngineModule.hpp>

//struct IEngineModule;

struct SModuleHandle
{
	SModuleHandle(void *apLibrary, IEngineModule *apModule)
		: pLibrary(apLibrary), pModule(apModule){}
	
	void *pLibrary{nullptr};
	IEngineModule *pModule{nullptr};
};

class CModuleLoader final // TODO: final static class?
{
public:
	/**
	 * Try to load a specified module by its name (path)
	 *
	 * @param asName - name of the module
	 * @return pointer to a valid heap-allocated SModuleHandle structure (see above) or nullptr if failed
	 */
	static SModuleHandle *LoadByName(const std::string &asName)
	{
		konbini::shared_lib ModuleLib(asName);
		
		if(!ModuleLib)
			return nullptr;
		
		auto pfnModuleMain{ModuleLib.getexportfunc<>("VEngineModuleMain")};
		
		if(!pfnModuleMain)
			return nullptr;
		
		auto pModule{pfnModuleMain()};
		
		if(!pModule)
			return nullptr;
		
		return new SModuleHandle(ModuleLib, pModule);
	};
};