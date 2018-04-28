/// @file
/// @brief console variable registry - used to register new variables or access already registered

#pragma once

struct ICvar;

struct ICvarRegistry
{
	/**
	 * Register a new variable
	 *
	 * @param asName - name of the variable
	 * @param asDefValue - default value
	 * @param asDescription - variable description (optional)
	 */
	virtual ICvar *Register(const char *asName, const char *asDefValue, const char *asDescription = "") = 0;
	
	/**
	 * Find a variable by its name
	 *
	 * @param asName - name of the variable
	 * @return pointer to a variable or nullptr if not found
	 */
	virtual ICvar *Find(const char *asName) const = 0;
};