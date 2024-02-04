/*
 * This file is part of V-Engine
 *
 * Copyright 2024 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include "VEngine.hpp"

#include <network/INetwork.hpp>
#include <physics/IPhysics.hpp>
#include <script/IScript.hpp>

#include <server/IEngineServer.hpp>
#include <client/IEngineClient.hpp>

#include "DedicatedServerMode.hpp"
#include "DedicatedClientMode.hpp"
#include "ListenServerMode.hpp"

CVEngine::~CVEngine()
{
	Shutdown();
};

bool CVEngine::Init(const InitProps &aInitProps)
{
	// TODO: load and init the core module here
	
	mpConfig = std::make_unique<CConfig>();
	
	// Do we have any config saved from the last run?
	if(!mpConfig->LoadFromFile("VEngineLast.ini"))
		mpConfig->LoadFromFile("VEngineDefault.ini");
	
	//if(!InitPhysics())
		//return false;
	
	bool bUseNetworking{false};
	
	// TODO
	bUseNetworking = true;
	
	if(bUseNetworking)
		if(!InitNetworking())
			return false;
	//else
		//mpNetwork = new CNetworkNull(); // TODO
	
	if(!InitScripting())
		return false;
	
	//
	
	switch(aInitParams.ExecMode)
	{
	case Mode::ListenServer:
		mpExecMode = std::make_unique<CListenServerMode>(new CDedicatedServerMode(), new CDedicatedClientMode()); // TODO: bad
		break;
	case Mode::DedicatedServer:
		mpExecMode = std::make_unique<CDedicatedServerMode>();
		break;
	case Mode::DedicatedClient:
		mpExecMode = std::make_unique<CDedicatedClientMode>();
		break;
	};
	
	mpExecMode->Init(mpEnv.get());
	return true;
};

void CVEngine::Frame()
{
	
};

void CVEngine::Shutdown()
{
	mpExecMode->Shutdown();
	
	//if(mpPhysics)
		//mpPhysics->Shutdown();
	
	if(mpNetwork)
		mpNetwork->Shutdown();
	
	if(mpScript)
		mpScript->Shutdown();
	
	mpConfig->SaveToFile("VEngineLast.ini"); // TODO: shouldn't it be above the call to execution mode?
	mpLogger->RemoveSink(mpLogSinkInternal);
};

bool CEngineCore::InitPhysics()
{
	static konbini::shared_lib PhysicsLib("VEnginePhysics");
	
	if(!PhysicsLib)
		return false;
	
	auto fnGetPhysics{PhysicsLib.getexportfunc<pfnGetPhysics>("GetPhysics")};
	
	if(!fnGetPhysics)
		return false;
	
	mpPhysics = fnGetPhysics(IPhysics::Version, *mpEnv);
	
	if(!mpPhysics)
		return false;
	
	return true;
};

bool CEngineCore::InitNetworking()
{
	static konbini::shared_lib NetworkLib("VEngineNetwork");
	
	if(!NetworkLib)
		return false;
	
	auto fnGetNetwork{NetworkLib.getexportfunc<pfnGetNetwork>("GetNetwork")};
	
	if(!fnGetNetwork)
		return false;
	
	mpNetwork = fnGetNetwork(INetwork::Version, *mpEnv);
	
	if(!mpNetwork)
		return false;
	
	if(!mpNetwork->Init())
		return false;
	
	return true;
};

bool CEngineCore::InitScripting()
{
	static konbini::shared_lib ScriptLib("VEngineScript");
	
	if(!ScriptLib)
		return false;
	
	auto fnGetScript{ScriptLib.getexportfunc<pfnGetScript>("GetScript")};
	
	if(!fnGetScript)
		return false;
	
	mpScript = fnGetScript(IScript::Version, *mpEnv);
	
	if(!mpScript)
		return false;
	
	if(!mpScript->Init())
		return false;
	
	return true;
};