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

#pragma once

//class CTimer;
class CConfig;

struct IEngineExecMode;

struct INetwork;
struct IPhysics;
struct IScript;

class CVEngine : public IVEngine
{
public:
	~CVEngine();
	
	///
	bool Init(const InitProps &aInitProps) override;
	
	void RequestClose() override {mbCloseRequested = true;}
private:
	void Shutdown();
	
	bool InitCore(const IEngineCore::InitParams &aInitProps);
	
	bool InitPhysics();
	bool InitNetworking();
	bool InitScripting();
private:
	//std::unique_ptr<CTimer> mpTimer;
	
	std::unique_ptr<CConfig> mpConfig;
	
	std::unique_ptr<IEngineExecMode> mpExecMode;
	
	IEngineCore *mpCore{nullptr};
	
	IPhysics *mpPhysics{nullptr};
	INetwork *mpNetwork{nullptr};
	IScript *mpScript{nullptr};
	
	bool mbCloseRequested{false};
};