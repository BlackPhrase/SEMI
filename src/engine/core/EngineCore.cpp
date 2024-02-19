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

#include <iostream>

#include "EngineCore.hpp"
#include "CoreEnv.hpp"
//#include "Timer.hpp"

#include "System.hpp"
#include "MemoryManager.hpp"
#include "Logger.hpp"

#include "SysVarRegistry.hpp"
#include "SysCmdRegistry.hpp"
#include "CmdProcessor.hpp"
#include "ThreadPool.hpp"

#include "LogSinkInternal.hpp"

CEngineCore::CEngineCore() = default;
CEngineCore::~CEngineCore() = default;

bool CEngineCore::Init(const IEngineCore::InitParams &aInitParams)
{
	if(mbInitialized)
	{
		mpSystem->Warning("Tried to double-init the core!"); // TODO: Error?
		return nullptr;
	};
	
	//using namespace std::chrono_literals;
	
	//mpTimer = std::make_unique<CTimer>(500ms); // TODO: THAT'S TOOO MUUUUUUUUUUUUUUUUUUUUUUUUUUUUCCH
	
	mpSystem = std::make_unique<CSystem>();
	
	mpMemoryManager = std::make_unique<CMemoryManager>();
	
	mpLogger = std::make_unique<CLogger>();
	mpLogSinkInternal = std::make_unique<CLogSinkInternal>();
	mpLogger->AddSink(mpLogSinkInternal.get());
	
	
	mpCvarRegistry = std::make_unique<CSysVarRegistry>();
	mpCmdRegistry = std::make_unique<CSysCmdRegistry>();
	
	mpCmdProcessor = std::make_unique<CCmdProcessor>(mpCmdRegistry.get());
	
	// Initialize the thread pool (worker threads)
	mpThreadPool = std::make_unique<CThreadPool>(atoi(mpConfig->GetString("General:WorkerThreads")));
	
	mpEnv = std::make_unique<CCoreEnv>(this, nullptr, mpMemoryManager.get(), mpLogger.get(), mpConfig.get(), mpCvarRegistry.get(), mpCmdRegistry.get(), mpCmdProcessor.get(), mpPhysics, mpNetwork);
	
	
	return true;
};

void CEngineCore::Shutdown()
{
	if(!mbInitialized)
	{
		std::cerr << "Tried to shutdown the uninitialized core!\n";
		return;
	};
	
	
	mpLogger->RemoveSink(mpLogSinkInternal);
};

bool CEngineCore::Frame()
{
	if(!mbInitialized)
	{
		std::cerr << "Tried to run a frame on the uninitialized core!\n";
		return false;
	};
	
	mpCmdProcessor->ExecPending();
	return true;
};