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