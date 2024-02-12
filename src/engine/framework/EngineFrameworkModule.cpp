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

#include <memory>

#include <vengine/CommonTypes.hpp>
#include <vengine/BaseEngineModule.hpp>

#include "VEngine.hpp"

class CEngineFrameworkModule : public CBaseEngineModule
{
public:
	CEngineFrameworkModule(const ICoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	
	bool OnLoad() override
	{
		RegisterInterface("VEngine", [=, this](int anVersion) -> void* {
			if(anVersion == IVEngine::Version)
			{
				if(!mpEngine)
					mpEngine.reset(new CVEngine(mCoreEnv));
				return mpEngine.get();
			};
			
			return nullptr;
		});

		
		return true;
	};
	
	bool OnUnload() override
	{
		mpEngine.reset(nullptr);
		
		return true;
	};
private:
	std::unique_ptr<CVEngine> mpEngine;
	
	const ICoreEnv &mCoreEnv;
};

C_EXPORT IEngineModule *VEngineModuleMain(const ICoreEnv &aCoreEnv)
{
	static CEngineFrameworkModule EngineFrameworkModule(aCoreEnv);
	return &EngineFrameworkModule;
};