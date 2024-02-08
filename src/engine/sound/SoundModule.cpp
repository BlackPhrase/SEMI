/*
 * This file is part of V-Engine
 *
 * Copyright 2018-2019, 2023-2024 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include <memory>

#include <vengine/CommonTypes.hpp>
#include <vengine/BaseEngineModule.hpp>

#include "Sound.hpp"

class CSoundModule : public CBaseEngineModule
{
public:
	CSoundModule(const ICoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	
	bool OnLoad() override
	{
		RegisterInterface("VEngineSound", [=, this](int anVersion) -> void* {
			if(anVersion == ISound::Version)
			{
				if(!mpSound)
					mpSound.reset(new CSound(mCoreEnv));
				return mpSound.get();
			};
			
			return nullptr;
		});
		
		return true;
	};
	
	bool OnUnload() override
	{
		mpSound.reset(nullptr);
		
		return true;
	};
private:
	std::unique_ptr<CSound> mpSound;
	
	const ICoreEnv &mCoreEnv;
};

C_EXPORT IEngineModule *VEngineModuleMain(const ICoreEnv &aCoreEnv)
{
	static CSoundModule SoundModule(aCoreEnv);
	return &SoundModule;
};