/*
 * This file is part of V-Engine
 *
 * Copyright 2018, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file
/// @brief client game interface

#pragma once

struct IEngineEnv;

struct IClientGame
{
	/// Interface version
	static constexpr auto Version{1};
	
	/**
	 * Initialize the game
	 *
	 * @param
	 * @return true if success
	 */
	virtual bool Init(IEngineEnv *apEngineEnv) = 0;
	
	/// Shutdown the game
	virtual void Shutdown() = 0;
	
	/// This will be called once every engine frame
	virtual void Frame() = 0;
};

using pfnGetClientGame = IClientGame *(*)(int anVersion);