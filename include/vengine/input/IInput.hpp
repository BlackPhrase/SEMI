/*
 * This file is part of V-Engine
 *
 * Copyright 2018-2019, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file
/// @brief input module interface

#pragma once

struct ICoreEnv;
struct IInputEventListener;

struct IInput
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	virtual void Update() = 0;
	
	/// Add a new event listener
	virtual void AddEventListener(IInputEventListener *apListener) = 0;
	
	/// Remove the registered event listener
	virtual void RemoveEventListener(IInputEventListener *apListener) = 0;
	
	///
	virtual bool IsKeyDown(int anKey) const = 0;
	
	///
	//virtual void BindKey(int anKey, const char *asCmd) = 0;
	
	///
	//virtual bool IsKeyBound(int anKey) const = 0;
	
	///
	//virtual const char *GetKeyBind(int anKey) const = 0;
	
	///
	//virtual int GetBoundKey(const char *asBind) const = 0;
	
	///
	//virtual SKeyData *GetKeyData(int anKey) const = 0;
	//virtual SKeyData *GetKeyData(const char *asKey) const = 0;
};

using pfnGetInput = IInput *(*)(int anVersion, const ICoreEnv &apCoreEnv);