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
/// @brief Engine module wrapper class

#pragma once

#include <vengine/IEngineModule.hpp>

class CEngineModule
{
public:
	CEngineModule(IEngineModule *apModule) : mpModule(apModule){}
	~CEngineModule() = default;
	
	/// Tries to execute all the necessary procedures to load the module
	/// @return true if the module was loaded, false otherwise
	bool Load();
	
	/// Tries to execute all the necessary procedures to unload the module
	/// @return true if the module was successfully unloaded or false in other case
	bool Unload();
	
	/// Tries to reload the module by first unloading it and then loading it again
	/// @return true or false depending on the result
	bool Reload();
	
	/// Possible states of the module
	enum class State : int
	{
		//Invalid = -1,
		Unloaded = 0,
		Loading,
		Failed, // TODO: InitFailed?
		Running,
		Unloading
	};
	
	/// @return current state of the module
	State GetState() const {return meState;}
	
	///
	template<typename T>
	T *GetInterface(const char *asName, int anVersion) const
	{
		return static_cast<T*>(mpModule->GetInterface(asName, anVersion));
	};
private:
	IEngineModule *mpModule{nullptr};
	
	State meState{State::Unloaded};
};