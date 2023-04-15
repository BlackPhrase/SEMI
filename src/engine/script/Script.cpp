/*
 * This file is part of V-Engine
 *
 * Copyright 2019, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include "Script.hpp"
#include "ScriptLua.hpp"

CScript::CScript(const ICoreEnv &apCoreEnv) : mpCoreEnv(apCoreEnv){}

CScript::~CScript() = default;

IScriptVM *CScript::CreateVM()
{
	return new CScriptLua();
};

void CScript::DestroyVM(IScriptVM *apVM)
{
	if(apVM)
	{
		delete apVM;
		apVM = nullptr;
	};
};