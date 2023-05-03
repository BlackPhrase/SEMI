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

#include "SysCmdRegistry.hpp"

CSysCmdRegistry::CSysCmdRegistry() = default;
CSysCmdRegistry::~CSysCmdRegistry() = default;

bool CSysCmdRegistry::Add(const char *asName, pfnCmdCallback afnCallback, const char *asDescription)
{
	if(Find(asName))
	{
		mpSystem->Error("Can't add a system command \"{}\", already present!", asName);
		return false;
	};
	
	auto pCmd{new CSysCmd(asName, afnCallback, asDescription)};
	mvCmds.push_back(pCmd);
	return true;
};

bool CSysCmdRegistry::Remove(const char *asName)
{
	if(!Find(asName))
		return false;
	
	// TODO
	return true;
};

CSysCmd *CSysCmdRegistry::Find(const char *asName) const
{
	for(auto It : mvCmds)
		if(!strcmp(It->GetName(), asName))
			return It;
	
	return nullptr;
};