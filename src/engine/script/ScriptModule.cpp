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

#include <vengine/CommonTypes.hpp>
#include <vengine/BaseEngineModule.hpp>

#include "Script.hpp"

class CScriptModule : public BaseEngineModule
{
public:
	CScriptModule(const ICoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CScriptModule() = default;
	
	bool OnLoad() override
	{
		RegisterInterface("VEngineScript", [=, this](int anVersion) -> void* {
			if(anVersion == IScript::Version)
			{
				if(!mpScript)
					mpScript = new CScript(mCoreEnv);
				return mpScript;
			};
			
			return nullptr;
		});
		
		return true;
	};
	
	bool OnUnload() override
	{
		if(mpScript)
		{
			delete mpScript;
			mpScript = nullptr;
		};
		
		return true;
	};
private:
	const ICoreEnv &mCoreEnv;
	
	IScript *mpScript{nullptr};
};

C_EXPORT IEngineModule *VEngineModuleMain(const ICoreEnv &aCoreEnv)
{
	static CScriptModule ScriptEngineModule(aCoreEnv);
	return &ScriptEngineModule;
};