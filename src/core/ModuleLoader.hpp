#pragma once

#include <string>
#include "vengine/IEngineModule.hpp"

//struct IEngineModule;

class CModuleLoader final
{
public:
	//CModuleLoader();
	//~CModuleLoader();
	
	static IEngineModule *LoadModule(const std::string &name)
	{
		return nullptr;
	};
};