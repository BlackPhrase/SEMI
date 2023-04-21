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
/// @brief base engine module implementation

#pragma once

#include <unordered_map>
#include <function>

#include "IEngineModule.hpp"

// NOTE: only for static strings!
using tInterfaceMap = std::unordered_map<std::string_view, std::function<void*(int)>>;

class CBaseEngineModule : public IEngineModule
{
public:
	void *GetInterface(const char *asName, int anVersion) const override final
	{
		return GetInterface(std::string_view(asName), anVersion);
	};
protected: // TODO: make public?
	/// A handy method to register new interface which then will be accessible through the GetInterface method
	/// @param Name of the interface
	/// @afnCallback A (lambda) function which will be used to (instantiate and) provide access to the actual interface, accepts an int as a requested version number
	void RegisterInterface(std::string_view asName, std::function<void*(int)> afnCallback)
	{
		mInterfaceMap[asName] = afnCallback;
	};
private:	
	void *GetInterface(std::string_view asName, int anVersion) const
	{
		// TODO: find?
		if(mInterfaceMap.contains(asName))
			return mInterfaceMap[asName](anVersion);
		
		return nullptr;
	};
private:
	tInterfaceMap mInterfaceMap; // TODO: unordered_set?
};