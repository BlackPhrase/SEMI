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
/// @brief scripting module interface

#pragma once

struct ICoreEnv;

struct IScriptVM
{
	///
	virtual void CallFunc(const char *asName) = 0;
};

struct IScript
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	virtual IScriptVM *CreateVM() = 0;
	
	///
	virtual void DestroyVM(IScriptVM *apVM) = 0;
};