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

#include <konbini/shared_lib.hpp>

#include <core/IEngineCore.hpp>

#include <network/INetwork.hpp>
#include <physics/IPhysics.hpp>
#include <script/IScript.hpp>

#include <server/IEngineServer.hpp>
#include <client/IEngineClient.hpp>

#include "Config.hpp"

#include "DedicatedServerMode.hpp"
#include "DedicatedClientMode.hpp"
#include "ListenServerMode.hpp"

CVEngine::~CVEngine()
{
	Shutdown();
};

bool CVEngine::Init(const InitProps &aInitProps)
{
	mpConfig = std::make_unique<CConfig>();
	
	// Do we have any config saved from the last run?
	if(!mpConfig->LoadFromFile("VEngineLast.ini"))
		mpConfig->LoadFromFile("VEngineDefault.ini");
	
	IEngineCore::InitParams CoreInitProps{};
	
	if(!InitCore(CoreInitProps))
		return false;
	
	//using namespace std::chrono_literals;
	
	//mpTimer = std::make_unique<CTimer>(500ms); // TODO: THAT'S TOOO MUUUUUUUUUUUUUUUUUUUUUUUUUUUUCCH
	
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
	
	//mpTimer->SetCallback([this](){mpExecMode->Frame();});
	
	return true;
};

void CVEngine::Frame()
{
	if(mbCloseRequested)
		return false;
	
	//mpExecMode->FrameBegin(); // mpEventDispatcher->DispatchEvent(Event::FrameBegin);
	
	mpCore->Frame(); // TODO: mpCmdProcessor->ExecPending();?
	
	if(mpNetwork)
		mpNetwork->Update();
	
	//mpTimer->Tick();
	
	//if(mpTimer->WantUpdate())
	//{
		//mpExecMode->Frame();
	//};
	
	//mpExecMode->HandleInput();
	
	mpExecMode->Frame(0.1f);
	
	//mpExecMode->Render();
	
	//mpExecMode->FrameEnd(); // mpEventDispatcher->DispatchEvent(Event::FrameEnd);
	return true;
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
};

bool CVEngine::InitCore(const IEngineCore::InitParams &aInitProps)
{
	static konbini::shared_lib CoreLib("VEngineCore");
	
	if(!CoreLib)
		return false;
	
	auto fnGetVEngineCore{CoreLib.getexportfunc<pfnGetVEngineCore>("GetVEngineCore")};
	
	if(!fnGetVEngineCore)
		return false;
	
	mpCore = fnGetVEngineCore(IEngineCore::Version);
	
	if(!mpCore)
		return false;
	
	if(!mpCore->Init(aInitProps))
		return false;
	
	return true;
};

bool CVEngine::InitPhysics()
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

bool CVEngine::InitNetworking()
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

bool CVEngine::InitScripting()
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