/*
 * This file is part of V-Engine
 *
 * Copyright 2018-2019, 2023-2024 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include "EngineModuleContainer.hpp"
#include "EngineModule.hpp"

CEngineModuleContainer::CEngineModuleContainer(const ICoreEnv &aCoreEnv, CModuleLoader &aLoader) : mCoreEnv(aCoreEnv), mLoader(aLoader){}

CEngineModuleContainer::~CEngineModuleContainer() = default;

bool CEngineModuleContainer::LoadModule(const char *asName, bool abCritical)
{
	bool bResult{LoadModule(asName)};
	
	if(!bResult)
		if(abCritical)
			mCoreEnv.GetSystem()->FatalError("Couldn't load the \"{}\" module!", asName);
		else
			mCoreEnv.GetSystem()->Warning("Couldn't load the \"{}\" module!", asName);
	
	return bResult;
};

bool CEngineModuleContainer::UnloadModule(int anIndex)
{
	return mvModules.at(anIndex)->Unload();
};

bool CEngineModuleContainer::ReloadModule(int anIndex)
{
	return mvModules.at(anIndex)->Reload();
};

void *CEngineModuleContainer::GetInterface(const char *asName, int anVersion) const
{
	void *pInterface{nullptr};
	
	for(auto It : mvModules)
		pInterface = It->GetInterface(asName, anVersion);
	
	return pInterface;
};

SModuleHandle *CEngineModuleContainer::LoadModule(const std::string &asName)
{
	auto pModule{mLoader.LoadByName(asName)};
	
	if(!pModule)
		return nullptr; // TODO: raise an error?
	
	mvModules.push_back(pModule);
	return pModule;
};

void CEngineModuleContainer::UnloadModule(SModuleHandle &aModule)
{
	// TODO
};

SModuleHandle *CEngineModuleContainer::GetByName(std::string_view asName) const
{
	for(auto It : mvModules)
		if(asName == It->GetName())
			return It;
	
	return nullptr;
};