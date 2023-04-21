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

#include <string_view>

#include <vengine/CommonTypes.hpp>
#include <vengine/BaseEngineModule.hpp>

#include "Game.hpp"

class CGameModule : public CBaseEngineModule
{
public:
	CGameModule(const ICoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	
	bool OnLoad() override
	{
		return true;
	};
	
	bool OnUnload() override
	{
		if(mpGame)
		{
			delete mpGame;
			mpGame = nullptr;
		};
		
		return true;
	};
public:
	void *GetInterface(std::string_view asName, int anVersion) const
	{
		if(asName == "VEngineGame"sv)
			if(anVersion == IGame::Version)
			{
				if(!mpGame)
					mpGame = new CGame();
				return mpGame;
			};
		
		return nullptr;
	};
private:
	const ICoreEnv &mCoreEnv;
	
	CGame *mpGame{nullptr};
};

C_EXPORT IEngineModule *VEngineModuleMain(const ICoreEnv &aCoreEnv)
{
	static CGameModule GameModule(aCoreEnv);
	return &GameModule;
};