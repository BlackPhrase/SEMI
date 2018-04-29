/// @file
/// @brief game interface

#pragma once

struct IEngineEnv;

struct IGame
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	virtual bool Init(IEngineEnv *apEngineEnv) = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual void Frame() = 0;
};

using pfnGetGame = IGame *(*)(int anVersion);