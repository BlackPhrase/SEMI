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

#include "DedicatedServerMode.hpp"
//#include "ModuleLoader.hpp"
#include "server/IEngineServer.hpp"
#include "shiftutil/shared_lib.hpp"

CDedicatedServerMode::CDedicatedServerMode() = default;
CDedicatedServerMode::~CDedicatedServerMode() = default;

void CDedicatedServerMode::Init(ICoreEnv *apCoreEnv)
{
	//auto EngServerModule{CModuleLoader::LoadModule("VEngineServer")};
	
	//auto EngServerFactory{EngServerModule->GetFactory()};
	
	//mpEngServer = EngServerFactory->GetInterface<IEngineServer>(IEngineServer::Version);
	
	static shiftutil::shared_lib EngineServerLib("VEngineServer");
	
	//if(!EngineServerLib)
		//return;
	
	auto fnGetEngineServer{EngineServerLib.getexportfunc<pfnGetEngineServer>("GetEngineServer")};
	
	if(!fnGetEngineServer)
		return;
	
	mpEngServer = fnGetEngineServer(IEngineServer::Version);
	
	if(!mpEngServer)
		return;
	
	mpEngServer->Init(apCoreEnv);
};

void CDedicatedServerMode::Shutdown()
{
	mpEngServer->Shutdown();
};

void CDedicatedServerMode::Frame(float afTimeStep)
{
	mpEngServer->Frame();
};