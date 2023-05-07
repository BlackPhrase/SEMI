/*
 * This file is part of V-Engine
 *
 * Copyright 2018, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#pragma once

#include <core/ICoreEnv.hpp>

struct IEngineCore;

class CCoreEnv final : public ICoreEnv
{
public:
	CCoreEnv(IEngineCore *apCore, ISystem *apSystem, IMemoryManager *apMemoryManager, IConfig *apConfig, IEngineModuleContainer *apEngineModuleContainer);
	~CCoreEnv();
	
	ISystem *GetSystem() const override {return mpSystem;}
	IMemoryManager *GetMemoryManager() const override {return mpMemoryManager;}
	IConfig *GetConfig() const override {return mpConfig;}
	IEngineModuleContainer *GetEngineModuleContainer() const override {return mpEngineModuleContainer;}
	
	//IPhysics *GetPhysics() const override {return mpPhysics;}
	//INetwork *GetNetwork() const override {return mpNetwork;}
	//IScript *GetScript() const override {return mpScript;}
	
	void Stop() override;
	
	//void SendCmd(const char *asText) override;
private:
	IEngineCore *mpCore{nullptr};
	
	ISystem *mpSystem{nullptr};
	IMemoryManager *mpMemoryManager{nullptr};
	IConfig *mpConfig{nullptr};
	IEngineModuleContainer *mpEngineModuleContainer{nullptr};
	
	//IPhysics *mpPhysics{nullptr};
	//INetwork *mpNetwork{nullptr};
	//IScript *mpScript{nullptr};
};