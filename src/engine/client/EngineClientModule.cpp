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

#include "EngineClient.hpp"

class CEngineClientModule : public CBaseEngineModule
{
public:
	CEngineClientModule(const ICoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	
	bool OnLoad() override
	{
		RegisterInterface("VEngineClient", [=, this](int anVersion) -> void* {
			if(anVersion == IEngineClient::Version)
			{
				if(!mpEngClient)
					mpEngClient = new CEngineClient();
				return mpEngClient;
			};
			
			return nullptr;
		});
		
		return true;
	};
	
	bool OnUnload() override
	{
		if(mpEngClient)
		{
			delete mpEngClient;
			mpEngClient = nullptr;
		};
		
		return true;
	};
private:
	const ICoreEnv &mCoreEnv;
	
	CEngineClient *mpEngClient{nullptr};
};

C_EXPORT IEngineModule *VEngineModuleMain(const ICoreEnv &aCoreEnv)
{
	static CEngineClientModule EngineClientModule;
	return &EngineClientModule;
};