/*
 * This file is part of V-Engine
 *
 * Copyright 2018-2019, 2024 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include <memory>

#include <vengine/CommonTypes.hpp>
#include <vengine/BaseEngineModule.hpp>

#include "Physics.hpp"

class CPhysicsModule : public CBaseEngineModule
{
public:
	CPhysicsModule(const ICoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	
	bool OnLoad() override
	{
		RegisterInterface("VEnginePhysics", [=, this](int anVersion) -> void* {
			if(anVersion == IPhysics::Version)
			{
				if(!mpPhysics)
					mpPhysics.reset(new CPhysics(mCoreEnv));
				return mpPhysics.get();
			};
			
			return nullptr;
		});
		
		return true;
	};
	
	bool OnUnload() override
	{
		mpPhysics.reset(nullptr);
		
		return true;
	};
private:
	std::unique_ptr<CPhysics> mpPhysics;
	
	const ICoreEnv &mCoreEnv;
};

C_EXPORT IEngineModule *VEngineModuleMain(const ICoreEnv &apCoreEnv)
{
	static CPhysicsModule PhysicsModule(aCoreEnv);
	return &PhysicsModule;
};