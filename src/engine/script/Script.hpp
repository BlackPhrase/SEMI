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

#pragma once

#include <script/IScript.hpp>

class CScript final : public IScript
{
public:
	CScript(const ICoreEnv &apCoreEnv);
	~CScript();
	
	IScriptVM *CreateVM() override;
	void DestroyVM(IScriptVM *apVM) override;
private:
	const ICoreEnv &mpCoreEnv;
};