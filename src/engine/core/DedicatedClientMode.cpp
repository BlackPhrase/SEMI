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

#include "DedicatedClientMode.hpp"
//#include "ModuleLoader.hpp"
#include "client/IEngineClient.hpp"
#include "shiftutil/shared_lib.hpp"

CDedicatedClientMode::CDedicatedClientMode() = default;
CDedicatedClientMode::~CDedicatedClientMode() = default;

void CDedicatedClientMode::Init(ICoreEnv *apCoreEnv)
{
	//auto EngClientModule{CModuleLoader::LoadModule("VEngineClient")};
	
	//auto EngClientFactory{EngClientModule->GetFactory()};
	
	//mpEngClient = EngClientFactory->GetInterface<IEngineClient>(IEngineClient::Version);
	
	static shiftutil::shared_lib EngineClientLib("VEngineClient");
	
	//if(!EngineClientLib)
		//return;
	
	auto fnGetEngineClient{EngineClientLib.getexportfunc<pfnGetEngineClient>("GetEngineClient")};
	
	if(!fnGetEngineClient)
		return;
	
	mpEngClient = fnGetEngineClient(IEngineClient::Version);
	
	if(!mpEngClient)
		return;
	
	mpEngClient->Init(apCoreEnv);
};

void CDedicatedClientMode::Shutdown()
{
	mpEngClient->Shutdown();
};

void CDedicatedClientMode::Frame(float afTimeStep)
{
	mpEngClient->Frame();
};