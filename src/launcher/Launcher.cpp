/*
 * This file is part of V-Engine
 *
 * Copyright 2017-2019, 2023-2024 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include <cstdlib>

#include <stdexcept>

#include <konbini/shared_lib.hpp>

#include <core/IEngineCore.hpp>
#include <framework/IVEngine.hpp>

IEngineCore *gpCore{nullptr};
IVEngine *gpEngine{nullptr};

bool Init(int argc, char **argv)
{
	IEngineCore::InitProps CoreInitProps{};
	
	CoreInitProps.msCmdLine = ""; // TODO
	
	auto pCoreEnv{gpCore->Init(CoreInitProps)};
	
	if(!pCoreEnv)
		return false;
	
	//
	
	pCoreEnv->GetModuleContainer()->LoadModule("VEngine", true);
	
	gpEngine = pCoreEnv->GetModuleContainer()->GetInterface<IVEngine>("IVEngine", IVEngine::Version);
	
	if(!gpEngine)
		return false;
	
	//
	
	IVEngine::InitProps VEngineInitProps{};
	
	// Allow to start the engine in dedicated client mode for developers
#ifdef VENGINE_DEV
	for(int i = 0; i < argc; ++i)
		if(!strcmp(argv[i], "-clientonly"))
			VEngineInitProps.ExecMode = IVEngine::ExecMode::DedicatedClient;
		
		// TODO: -language
#endif
	
	if(!gpEngine->Init(VEngineInitProps))
		return false;
	
	//
	
	return true;
};

void Run()
{
	while(gpCore->Frame()) // TODO: geez...
		;
	
	gpCore->Shutdown();
};

int VEngineMain(int argc, char **argv)
{
	konbini::shared_lib EngineCoreLib("VEngineCore");
	
	if(!EngineCoreLib)
		throw std::runtime_error("Failed to load the engine core module!");
	
	auto fnGetEngineCore{EngineCoreLib.getexportfunc<pfnGetEngineCore>("GetEngineCore")};
	
	if(!fnGetEngineCore)
		throw std::runtime_error("Failed to access the engine core export!");
	
	auto pCore{fnGetEngineCore(IEngineCore::Version)};
	
	if(!pCore)
		throw std::runtime_error("Failed to acquire the engine core interface!");
	
	gpCore = pCore;
	
	//
	
	if(!Init(argc, argv))
		throw std::runtime_error("Failed to initialize the engine core!");
	
	Run();
	
	//
	
	return EXIT_SUCCESS;
};