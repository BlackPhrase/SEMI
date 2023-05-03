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

#include <algorithm>
#include <cstring>

#include "Cvar.hpp"
#include "CvarRegistry.hpp"

CCvarRegistry::CCvarRegistry() = default;
CCvarRegistry::~CCvarRegistry() = default;

ISysVar *CCvarRegistry::Add(const char *asName, const char *asDefValue, const char *asDescription)
{
	// Check if already registered
	auto pVar{Find(asName)}; // TODO
	
	if(pVar)
		return pVar;
	
	//return mvVars.emplace_back(asName, asDefValue, asDescription);
	pVar = new CSysVar(asName, asDefValue, asDescription); // TODO: release
	mvVars.push_back(pVar);
	return pVar;
};

bool CCvarRegistry::Register(ISysVar *apVar)
{
	auto sName{apVar->GetName()};
	
	// Check if another cvar with the same name already registered
	if(Find(sName))
	{
		mpSystem->Error("Can't register a system variable \"{}\", already registered!", sName);
		return false;
	};
	
	mvVars.push_back(apVar);
	return true;
};

bool CCvarRegistry::Remove(const char *asName)
{
	auto pVar{Find(asName)};
	
	if(!pVar)
		return false;
	
	std::remove(mvVars.begin(), mvVars.end(), pVar);
	return false;
};

ISysVar *CCvarRegistry::Find(const char *asName) const
{
	for(auto It : mvVars)
		if(!strcmp(It->GetName(), asName))
			return It;
	
	return nullptr;
};