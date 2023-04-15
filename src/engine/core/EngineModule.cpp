/*
 * This file is part of V-Engine
 *
 * Copyright 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include "EngineModule.hpp"

bool CEngineModule::Load()
{
	meState = State::Loading;
	
	if(mpModule->OnLoad())
	{
		meState = State::Running;
		return true;
	};
	
	meState = State::Failed;
	return false;
};

bool CEngineModule::Unload()
{
	meState = State::Unloading;
	
	if(mpModule->OnUnload())
	{
		meState = State::Unloaded;
		return true;
	};
	
	//meState = State::Failed; // Can't be unloaded if used by (an)other module(s), but should we switch the state?
	return false;
};

bool CEngineModule::Reload()
{
	if(!Unload())
		return false;
	
	if(!Load())
		return false;
	
	//return mpModule->OnReload();
	return true;
};