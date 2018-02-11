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

class CModuleLoader final
{
public:
	//CModuleLoader();
	//~CModuleLoader();
	
	static IEngineModule *LoadModule(const std::string &name)
	{
		shiftutil::shared_lib ModuleLib(name.c_str()); // TODO: why only C-string?
		
		//if(!ModuleLib)
			//return nullptr;
		
		auto pfnModuleMain{ModuleLib.getexportfunc<>("VEngineModuleMain")};
		
		if(!pfnModuleMain)
			return nullptr;
		
		auto pModule{pfnModuleMain()};
		
		if(!pModule)
			return nullptr;
		
		return pModule;
	};
};