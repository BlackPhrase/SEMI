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

#include <CommonTypes.hpp>
#include <BaseEngineModule.hpp>

#include "EngineServer.hpp"

class CEngineServerModule : public CBaseEngineModule
{
public:
	CEngineServerModule(const ICoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	
	bool OnLoad() override
	{
		RegisterInterface("VEngineServer", [=, this](int anVersion) -> void* {
			if(anVersion == IEngineServer::Version)
			{
				if(!mpEngServer)
					mpEngServer = new CEngineServer();
				return mpEngServer;
			};
			
			return nullptr;
		});
		
		return true;
	};
	
	bool OnUnload() override
	{
		if(mpEngServer)
		{
			delete mpEngServer;
			mpEngServer = nullptr;
		};
		
		return true;
	};
private:
	const ICoreEnv &mCoreEnv;
	
	CEngineServer *mpEngServer{nullptr};
};

C_EXPORT IEngineModule *VEngineModuleMain(const ICoreEnv &aCoreEnv)
{
	static CEngineServerModule EngineServerModule(aCoreEnv);
	return &EngineServerModule;
};