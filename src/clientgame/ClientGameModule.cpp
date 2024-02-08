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

#include <CommonTypes.hpp>
#include <BaseEngineModule.hpp>

#include "ClientGame.hpp"

class CClientGameModule : public CBaseEngineModule
{
public:
	CClientGameModule(const ICoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	
	bool OnLoad() override
	{
		RegisterInterface("VEngineClientGame", [=, this](int anVersion) -> void* {
			if(anVersion == IClientGame::Version)
			{
				if(!mpClientGame)
					mpClientGame = new CClientGame();
				return mpClientGame;
			};
			
			return nullptr;
		});
		
		return true;
	};
	
	bool OnUnload() override
	{
		if(mpClientGame)
		{
			delete mpClientGame;
			mpClientGame = nullptr;
		};
		
		return true;
	};
private:
	const ICoreEnv &mCoreEnv;
	
	CClientGame *mpClientGame{nullptr};
};

C_EXPORT IEngineModule *VEngineModuleMain(const ICoreEnv &aCoreEnv)
{
	static CClientGameModule ClientGameModule(aCoreEnv);
	return &ClientGameModule;
};