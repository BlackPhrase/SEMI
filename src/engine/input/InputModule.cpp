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

#include "Input.hpp"
#include "InputEventDispatcher.hpp"

class CInputModule : public CBaseEngineModule
{
public:
	CInputModule(const ICoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	
	bool OnLoad() override
	{
		RegisterInterface("VEngineInput", [=, this](int anVersion) -> void* {
			if(anVersion == IInput::Version)
			{
				if(!mpInput)
				{
					mpInputEventDispatcher = new CInputEventDispatcher();
					mpInput = new CInput(mCoreEnv, mpInputEventDispatcher, nullptr);
				};
				return mpInput;
			};
			
			return nullptr;
		});
		
		return true;
	};
	
	bool OnUnload() override
	{
		if(mpInput)
		{
			delete mpInput;
			delete mpInputEventDispatcher;
			
			mpInput = nullptr;
		};
		
		return true;
	};
private:
	const ICoreEnv &mCoreEnv;
	
	CInput *mpInput{nullptr};
	CInputEventDispatcher *mpInputEventDispatcher{nullptr};
};

C_EXPORT IEngineModule *VEngineModuleMain(const ICoreEnv &aCoreEnv)
{
	static CInputModule InputModule(aCoreEnv);
	return &InputModule;
};