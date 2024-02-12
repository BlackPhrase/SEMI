/*
 * This file is part of V-Engine
 *
 * Copyright 2017-2019, 2023-2024 BlackPhrase
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
	
	/// Core initialization properties
	struct InitProps
	{
		//const char *msCmdLine{""}; ///< App's launch arguments
		int argc{-1};
		char **argv{nullptr};
	};
	
	/**
	 * Try to initialize the core
	 *
	 * @param InitProps Initialization properties
	 * @return true if success, false otherwise
	 */
	virtual bool Init(const InitProps &aInitProps, ICoreEnv &aCoreEnv) = 0; // TODO: should this return the core environment?
	//virtual ICoreEnv *Init(const InitProps &aInitProps) = 0;
	
	/// Shutdown the core (if initialized)
	virtual void Shutdown() = 0; // TODO: remove?
	
	/// Run a single frame
	/// @return true or false depending on the result
	virtual bool Frame() = 0;
};

using pfnGetEngineCore = IEngineCore *(*)(int anVersion);