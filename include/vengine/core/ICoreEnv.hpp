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
/// @brief core environment interface - provides a set of common interfaces

#pragma once

struct ICommandLine;
struct IMemoryManager;
struct ILogger;
struct IConfig;
struct ICvarRegistry;
struct ICmdRegistry;
struct ICmdProcessor;
struct IPhysics;
struct INetwork;
struct IScript;

struct ICoreEnv
{
	///
	virtual ICommandLine *GetCommandLine() const = 0;
	
	///
	virtual IMemoryManager *GetMemoryManager() const = 0;
	
	///
	virtual ILogger *GetLogger() const = 0;
	
	///
	virtual IConfig *GetConfig() const = 0;
	
	///
	virtual ICvarRegistry *GetCvarRegistry() const = 0;
	
	///
	virtual ICmdRegistry *GetCmdRegistry() const = 0;
	
	///
	virtual ICmdProcessor *GetCmdProcessor() const = 0;
	
	///
	virtual IPhysics *GetPhysics() const = 0;
	
	///
	virtual INetwork *GetNetwork() const = 0;
	
	///
	virtual IScript *GetScript() const = 0;
	
	///
	virtual void Stop() = 0;
	
	///
	//virtual void SendCmd(const char *asText) = 0;
};