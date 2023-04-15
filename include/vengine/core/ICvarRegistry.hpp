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
/// @brief console variable registry - used to register new variables or access already registered

#pragma once

struct ICvar;

struct ICvarRegistry
{
	/**
	 * Create a new variable
	 *
	 * @param asName - name of the variable
	 * @param asDefValue - default value
	 * @param asDescription - variable description (optional)
	 * @return pointer to a newly created variable
	 */
	virtual ICvar *Add(const char *asName, const char *asDefValue, const char *asDescription = "") = 0;
	
	/**
	 * Register an already present variable
	 *
	 * @param apCvar - pointer to the variable
	 * @return true in success
	 */
	//virtual bool Register(ICvar *apCvar) = 0;
	
	/**
	 * Find a variable by its name
	 *
	 * @param asName - name of the variable
	 * @return pointer to a variable or nullptr if not found
	 */
	virtual ICvar *Find(const char *asName) const = 0;
	
	/**
	 * Remove an already present variable
	 *
	 * @param asName - name of the variable
	 */
	virtual void Remove(const char *asName) = 0;
};