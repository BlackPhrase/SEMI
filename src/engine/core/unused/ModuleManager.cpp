/// @file

#include "ModuleManager.hpp"

SModuleHandle *CModuleManager::LoadModule(const std::string &asName)
{
	auto pModule{mpLoader->LoadByName(asName)};
	
	if(!pModule)
		return nullptr; // TODO: raise an error?
	
	mvModules.push_back(pModule);
	return pModule;
};

void CModuleManager::UnloadModule(SModuleHandle *apModule)
{
	// TODO
};

SModuleHandle *CModuleManager::GetModule(const std::string &asName) const
{
	for(auto It : mvModules)
		if(!strcmp(It->GetName(), asName.c_str()))
			return It;
	
	return nullptr;
};