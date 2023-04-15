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
		Host = 0,         ///< Run in host mode (client + server)
		DedicatedServer,  ///< Run in dedicated server mode (server-only)
		DedicatedClient   ///< Run in dedicated client mode (client-only)
	};
	
	/// Core initialization preferences
	struct InitProps
	{
		Mode meExecMode{Mode::Host}; ///< Requested execution mode
		
		const char *msCmdLine{""}; ///< App's launch arguments
		//int argc{-1};
		//char **argv{nullptr};
	};
	
	/**
	 * Try to initialize the core
	 *
	 * @param InitProps Initialization preferences
	 * @return true if success, false otherwise
	 */
	virtual bool Init(const InitProps &aInitProps) = 0;
	
	/// Shutdown the core (if initialized)
	virtual void Shutdown() = 0; // TODO: remove?
	
	/// Run a single frame
	/// @return true or false depending on the result
	virtual bool Frame() = 0;
	
	/// Request engine to shutdown
	virtual void RequestClose() = 0;
};

using pfnGetEngineCore = IEngineCore *(*)(int anVersion);