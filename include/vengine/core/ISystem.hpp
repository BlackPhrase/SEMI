/*
 * This file is part of V-Engine
 *
 * Copyright 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#pragma once

#include <cstdint>
//#include <source_location>

struct ICmdProcessor;

//struct ISysCmd;
struct ICmdArgs;

using pfnCmdCallback = void (*)(const ICmdArgs &aArgs);

struct ISysVar;

struct ILogSink
{
	///
	virtual void OnMessage(const char *asFile, int anLine, const char *asMsg) = 0;
};

struct ISystem
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	virtual void AddLogSink(ILogSink *apSink) = 0;
	
	///
	virtual void RemoveLogSink(ILogSink *apSink) = 0;
	
	///
	virtual void LogMessage(const char *asFile, int anLine, const char *asMsg, ...) = 0;
	
	///
	template<typename... Args>
	inline void Message(const char *asMsg, Args&&... args)
	{
		LogMessage(__FILE__, __LINE__, asMsg, args...); //std::forward<Args>(args)...);
	};
	
	///
	virtual void impl_log(eMsgType aeType, const char *asMsg, const char *asFileName, uint_least32_t anLine) = 0;
	
	///
	inline void Log(const char *asMsg, ...)
	{
		impl_log(eMsgType::Info, asMsg, __FILE__, __LINE__);
		//impl_log(eMsgType::Info, asMsg, std::experimental::source_location::current::file_name(), std::experimental::source_location::current::line());
	};
	
	///
	inline void Warning(const char *asMsg, ...)
	{
		impl_log(eMsgType::Warning, asMsg, __FILE__, __LINE__);
	};
	
	///
	inline void Error(const char *asMsg, ...)
	{
		impl_log(eMsgType::Error, asMsg, __FILE__, __LINE__);
	};
	
	///
	inline void FatalError(const char *asMsg, ...)
	{
		impl_log(eMsgType::Error, asMsg, __FILE__, __LINE__);
		Quit();
	};
	
	/**
	 * Register a new command
	 *
	 * @param asName Name of the command
	 * @param afnCallback A callback function that will be called
	 * @param asDescription The command description string (optional)
	 * @return true on success, false otherwise
	 */
	virtual bool AddCmd(const char *asName, pfnCmdCallback afnCallback, const char *asDescription = "") = 0;
	
	///
	//virtual bool RegisterCmd(ISysCmd *apCmd) = 0;
	
	/**
	 * Removes an already registered command (if present)
	 *
	 * @param asName Name of the command
	 * @return true or false depending on the result
	 */
	virtual bool RemoveCmd(const char *asName) = 0;
	
	/**
	 * Find a command by its name
	 *
	 * @param asName Name of the command
	 * @return Pointer to a command or nullptr if not found
	 */
	//virtual ISysCmd *FindCmd(const char *asName) const = 0;
	
	/**
	 * Create a new variable
	 *
	 * @param asName Name of the variable
	 * @param asDefValue Default value
	 * @param asDescription Variable description (optional)
	 * @return Pointer to a newly created variable
	 */
	virtual ISysVar *AddVar(const char *asName, const char *asDefValue, const char *asDescription = "") = 0;
	
	/**
	 * Register an already present variable
	 *
	 * @param apVar Pointer to the variable
	 * @return true on success, false otherwise
	 */
	//virtual bool RegisterVar(ISysVar *apVar) = 0;
	
	/**
	 * Remove an already present variable
	 *
	 * @param asName Name of the variable
	 * @return true of false depending on the result
	 */
	virtual bool RemoveVar(const char *asName) = 0;
	
	/**
	 * Find a variable by its name
	 *
	 * @param asName Name of the variable
	 * @return Pointer to a variable or nullptr if not found
	 */
	virtual ISysVar *FindVar(const char *asName) const = 0;
	
	///
	virtual ICmdProcessor *GetCmdProcessor() const = 0;
};