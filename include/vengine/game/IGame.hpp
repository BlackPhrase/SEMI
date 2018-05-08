/// @file
/// @brief server-side game interface

#pragma once

struct IEngineEnv;

struct IGame
{
	/// Interface version
	static constexpr auto Version{1};
	
	/// Initialize the game module
	virtual bool Init(IEngineEnv *apEngineEnv) = 0;
	
	/// Shutdown the game
	virtual void Shutdown() = 0;
	
	/// Runs a single frame
	virtual void Frame() = 0;
};

using pfnGetGame = IGame *(*)(int anVersion);