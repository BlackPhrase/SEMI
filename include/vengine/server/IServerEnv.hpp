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
/// @brief server-side engine environment interface - contains a set of interfaces accessible to use by the server-side game

#pragma once

//#include <core/ISystem.hpp>

struct ISystem;
struct IPhysics;
struct IScript;
struct INetServer;

struct IEngineEnv
{
	///
	virtual ISystem *GetSystem() const = 0;
	
	///
	virtual IPhysics *GetPhysics() const = 0;
	
	///
	virtual IScript *GetScript() const = 0;
	
	///
	virtual INetServer *GetServer() const = 0;
};