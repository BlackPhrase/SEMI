/// @file
/// @brief console command registry - used to register new commands or access already registered

#pragma once

//struct ICmd;

using pfnCmdCallback = void (*)();

struct ICmdRegistry
{
	/**
	 * Register a new command
	 *
	 * @param asName - name of the command
	 * @param afnCallback - callback function that will be called
	 * @param asDescription - command description (optional)
	 */
	virtual void Register(const char *asName, pfnCmdCallback afnCallback, const char *asDescription = "") = 0;
	
	/**
	 * Find a command by its name
	 *
	 * @param asName - name of the command
	 * @return pointer to a command or nullptr if not found
	 */
	//virtual ICvar *Find(const char *asName) const = 0;
	
	///
	//virtual void Remove(const char *asName) = 0;
};