/*
 * This file is part of V-Engine
 *
 * Copyright 2018-2019, 2023 BlackPhrase
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
	
	VEngineInitProps.meExecMode = IEngineCore::Mode::DedicatedServer;
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

int main(int argc, char **argv)
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