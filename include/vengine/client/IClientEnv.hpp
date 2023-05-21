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
/// @brief client-side engine environment interface - contains a set of interfaces accessible to use by the client-side game

#pragma once

//#include <core/ILogger.hpp>

struct ISystem;
struct INetClient;
struct IInput;
struct IPhysics;
struct IResourceManager;
struct IScript;
struct ISound;

struct IEngineEnv
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	//virtual int GetVersion() const {return Version;}
	
	///
	virtual ISystem *GetSystem() const = 0;
	
	///
	virtual INetClient *GetNetClient() const = 0;
	
	///
	virtual IInput *GetInput() const = 0;
	
	///
	virtual IPhysics *GetPhysics() const = 0;
	
	///
	virtual IResourceManager *GetResourceManager() const = 0;
	
	///
	virtual IScript *GetScript() const = 0;
	
	///
	virtual ISound *GetSound() const = 0;
};