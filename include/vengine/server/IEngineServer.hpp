/// @file
/// @brief engine server interface

#pragma once

struct ICoreEnv;

struct IEngineServer
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	virtual bool Init(ICoreEnv *apCoreEnv) = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual void Frame() = 0;
};

using pfnGetEngineServer = IEngineServer *(*)(int anVersion);