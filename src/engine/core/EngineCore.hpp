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

#pragma once

#include <memory>

#include <core/IEngineCore.hpp>

#include "CmdArgs.hpp"

struct IEngineExecMode;
struct INetwork;
struct IPhysics;
struct IScript;
//class CTimer;
class CCoreEnv;

class CSystem;
class CMemoryManager;
class CLogger;
class CConfig;
class CSysVarRegistry;
class CSysCmdRegistry;
class CCmdProcessor;
class CThreadPool;

class CLogSinkInternal;

class CEngineCore final : public IEngineCore
{
public:
	CEngineCore();
	~CEngineCore();
	
	bool Init(const IEngineCore::InitParams &aInitParams) override;
	void Shutdown() override;
	
	bool Frame() override;
	
	void RequestClose() override {mbCloseRequested = true;}
private:
	bool InitPhysics();
	bool InitNetworking();
	bool InitScripting();
	
	std::unique_ptr<IEngineExecMode> mpExecMode;
	//std::unique_ptr<CTimer> mpTimer;
	
	std::unique_ptr<CCoreEnv> mpEnv;
	
	std::unique_ptr<CSystem> mpSystem;
	std::unique_ptr<CMemoryManager> mpMemoryManager;
	std::unique_ptr<CLogger> mpLogger;
	std::unique_ptr<CConfig> mpConfig;
	
	std::unique_ptr<CSysVarRegistry> mpVarRegistry;
	std::unique_ptr<CSysCmdRegistry> mpCmdRegistry;
	
	std::unique_ptr<CCmdProcessor> mpCmdProcessor;
	
	std::unique_ptr<CThreadPool> mpThreadPool;
	
	std::unique_ptr<CLogSinkInternal> mpLogSinkInternal;
	
	CStartupArgs mCmdLine;
	
	IPhysics *mpPhysics{nullptr};
	INetwork *mpNetwork{nullptr};
	IScript *mpScript{nullptr};
	
	bool mbCloseRequested{false};
};