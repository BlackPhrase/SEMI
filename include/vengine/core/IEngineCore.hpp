/*
 * This file is part of V-Engine
 *
 * Copyright 2017-2019, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file
/// @brief engine core interface

#pragma once

struct IEngineCore
{
	/// Interface version
	static constexpr auto Version{1};
	
	/// Core initialization mode
	enum class Mode : int
	{
		ListenServer = 0, ///< Run as listenserver (client + server)
		DedicatedServer,  ///< Run in dedicated server mode (server-only)
		DedicatedClient   ///< Run in dedicated client mode (client-only)
	};
	
	/// Core initialization preferences
	struct InitParams
	{
		Mode ExecMode{Mode::ListenServer}; ///<
	};
	
	/**
	 * Try to initialize the core
	 *
	 * @param InitParams - initialization preferences
	 * @return true if success
	 */
	virtual bool Init(const InitParams &aInitParams) = 0;
	
	/// Shutdown the core (if initialized)
	virtual void Shutdown() = 0;
	
	/// Run a single frame
	virtual bool Frame() = 0;
	
	/// Request engine to shutdown
	virtual void RequestClose() = 0;
};

using pfnGetEngineCore = IEngineCore *(*)(int anVersion);