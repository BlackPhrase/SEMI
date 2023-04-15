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

#include <vengine/CommonTypes.hpp>
#include <vengine/IEngineModule.hpp>

#include "Script.hpp"

class CScriptModule : public IEngineModule
{
public:
	CScriptModule(const ICoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CScriptModule() = default;
	
	bool OnLoad() override
	{
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
	
	void *GetInterface(const char *asName, int anVersion) const override
	{
		if(!strcmp(asName, "VEngineScript"))
			if(anVersion == IScript::Version)
			{
				if(!mpScript)
					mpScript = new CScript(mCoreEnv);
				return mpScript;
			};
		
		return nullptr;
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