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

#include <cstdlib>

#include <stdexcept>

#include <konbini/shared_lib.hpp>
#include <core/IEngineCore.hpp>

IEngineCore *gpEngine{nullptr};

bool Init()
{
	IEngineCore::InitProps VEngineInitProps{};
	
	// Allow to start the engine in dedicated client mode for developers
#ifdef VENGINE_DEV
	for(int i = 0; i < argc; ++i)
		if(!strcmp(argv[i], "-clientonly"))
			VEngineInitProps.ExecMode = IEngineCore::Mode::DedicatedClient;
#endif
	
	VEngineInitProps.msCmdLine = ""; // TODO
	
	if(!gpEngine->Init(VEngineInitProps))
		return false;
	
	return true;
};

void Run()
{
	while(gpEngine->Frame()) // TODO: geez...
		;
	
	gpEngine->Shutdown();
};

int VEngineMain(int argc, char **argv)
{
	konbini::shared_lib EngineCoreLib("VEngineCore");
	
	if(!EngineCoreLib)
		throw std::runtime_error("Failed to load the engine core module!");
	
	auto fnGetEngineCore{EngineCoreLib.getexportfunc<pfnGetEngineCore>("GetEngineCore")};
	
	if(!fnGetEngineCore)
		throw std::runtime_error("Failed to access the engine core export!");
	
	auto pEngine{fnGetEngineCore(IEngineCore::Version)};
	
	if(!pEngine)
		throw std::runtime_error("Failed to acquire the engine core interface!");
	
	gpEngine = pEngine;
	
	if(!Init())
		throw std::runtime_error("Failed to initialize the engine core!");
	
	Run();
	
	return EXIT_SUCCESS;
};