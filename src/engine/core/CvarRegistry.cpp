/// @file

#include <cstring>

#include "Cvar.hpp"
#include "CvarRegistry.hpp"

CCvarRegistry::CCvarRegistry() = default;
CCvarRegistry::~CCvarRegistry() = default;

ICvar *CCvarRegistry::Register(const char *asName, const char *asDefValue, const char *asDescription)
{
	// Check if already registered
	ICvar *pVar = Find(asName);
	
	if(pVar)
		return pVar;
	
	//return mvVars.emplace_back(asName, asDefValue, asDescription);
	CCvar *pCvar = new CCvar(asName, asDefValue, asDescription);
	mvVars.push_back(pCvar);
	return pCvar;
};

ICvar *CCvarRegistry::Find(const char *asName) const
{
	for(auto It : mvVars)
		if(!strcmp(It->GetName(), asName))
			return It;
	
	return nullptr;
};