#pragma once

struct IEngineModule;

class CModuleLoader final
{
public:
	CModuleLoader();
	~CModuleLoader();
	
	IEngineModule *LoadModule(const std::string &name)
	{
		return nullptr;
	};
};