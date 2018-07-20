/// @file
/// @brief client-side engine environment interface - contains a set of interfaces accessible to use by the client-side game

#pragma once

struct ILogger;
struct ICmdRegistry;
struct ICvarRegistry;
struct IInputEventDispatcher;
//struct IInput;
struct IPhysics;
struct IResourceManager;

struct IEngineEnv
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	//virtual int GetVersion() const {return Version;}
	
	///
	virtual ILogger *GetLogger() const = 0;
	
	///
	virtual ICmdRegistry *GetCmdRegistry() const = 0;
	
	///
	virtual ICvarRegistry *GetCvarRegistry() const = 0;
	
	///
	virtual IInputEventDispatcher *GetInputEventDispatcher() const = 0;
	
	///
	//virtual IInput *GetInput() const = 0;
	
	///
	virtual IPhysics *GetPhysics() const = 0;
	
	///
	virtual IResourceManager *GetResourceManager() const = 0;
};