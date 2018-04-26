/// @file
/// @brief module loader - actually used to load modules

#pragma once

#include <string>

#include "vengine/IEngineModule.hpp"
#include "shiftutil/shared_lib.hpp"

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
		shiftutil::shared_lib ModuleLib(asName.c_str()); // TODO: why only C-string?
		
		//if(!ModuleLib)
			//return nullptr;
		
		auto pfnModuleMain{ModuleLib.getexportfunc<>("VEngineModuleMain")};
		
		if(!pfnModuleMain)
			return nullptr;
		
		auto pModule{pfnModuleMain()};
		
		if(!pModule)
			return nullptr;
		
		return new SModuleHandle(ModuleLib, pModule);
	};
};