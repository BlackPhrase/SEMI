/// @file
/// @brief core environment interface - provides a set of common interfaces

#pragma once

struct ICvarRegistry;
struct ICmdRegistry;
struct IPhysics;
struct INetwork;

struct ICoreEnv
{
	///
	virtual ICvarRegistry *GetCvarRegistry() const = 0;
	
	///
	virtual ICmdRegistry *GetCmdRegistry() const = 0;
	
	///
	virtual IPhysics *GetPhysics() const = 0;
	
	///
	virtual INetwork *GetNetwork() const = 0;
	
	///
	virtual void Stop() = 0;
	
	///
	//virtual void SendCmd(const char *asText) = 0;
};