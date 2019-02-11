/// @file
/// @brief server-side engine environment interface - contains a set of interfaces accessible to use by the server-side game

#pragma once

#include "core/ILogger.hpp"

struct ICmdRegistry;
struct ICvarRegistry;
struct IPhysics;
struct IScript;
struct INetServer;

struct IEngineEnv
{
	///
	virtual ILogger *GetLogger() const = 0;
	
	///
	virtual ICmdRegistry *GetCmdRegistry() const = 0;
	
	///
	virtual ICvarRegistry *GetCvarRegistry() const = 0;
	
	///
	virtual IPhysics *GetPhysics() const = 0;
	
	///
	virtual IScript *GetScript() const = 0;
	
	///
	virtual INetServer *GetServer() const = 0;
};