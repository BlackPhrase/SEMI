/*
 * This file is part of V-Engine
 *
 * Copyright 2018, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file
/// @brief console command registry - used to register new commands or access already registered

#pragma once

//struct ICmd;
struct ICmdArgs;

using pfnCmdCallback = void (*)(const ICmdArgs &apArgs);

struct ICmdRegistry
{
	/**
	 * Register a new command
	 *
	 * @param asName - name of the command
	 * @param afnCallback - callback function that will be called
	 * @param asDescription - command description (optional)
	 */
	virtual void Add(const char *asName, pfnCmdCallback afnCallback, const char *asDescription = "") = 0;
	
	/**
	 * Find a command by its name
	 *
	 * @param asName - name of the command
	 * @return pointer to a command or nullptr if not found
	 */
	//virtual ICmd *Find(const char *asName) const = 0;
	
	/**
	 * Removes an already registered command (if present)
	 *
	 * @param asName - name of the command
	 */
	virtual void Remove(const char *asName) = 0;
};