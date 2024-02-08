/*
 * This file is part of V-Engine
 *
 * Copyright 2018-2019, 2023-2024 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file
/// @brief engine module container - stores loaded module instances inside and provides access to them

#pragma once

#include <CommonTypes.hpp>
#include <core/IEngineModuleContainer.hpp>

struct ICoreEnv;

struct SModuleHandle;
using tModuleHandleVec = std::vector<SModuleHandle*>;

class CEngineModuleContainer final : public IEngineModuleContainer
{
public:
	CEngineModuleContainer(const ICoreEnv &aCoreEnv);
	~CEngineModuleContainer();
public: // IEngineModuleContainer interface impl
	bool LoadModule(const char *asName, bool abCritical = false) override;
	bool UnloadModule(int anIndex) override;
	bool ReloadModule(int anIndex) override;
	
	void *GetInterface(const char *asName, int anVersion) const override;
public: // Other public methods
	/// Use this to load a module using its name
	/// @return pointer to the loaded module or nullptr if failed
	SModuleHandle *LoadModule(const std::string &asName);
	
	/// Unload a module by its handle
	void UnloadModule(SModuleHandle &aModule);
	
	/// Get module by its index
	SModuleHandle *GetByIndex(int anID) const {return mvModules.at(anID);}
	
	/// Get module by its name
	SModuleHandle *GetByName(std::string_view asName) const;
private:
	tModuleHandleVec mvModules;
	
	const ICoreEnv &mCoreEnv;
};