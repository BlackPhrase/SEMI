/// @file

#include <algorithm>
#include <cstring>

#include "Cvar.hpp"
#include "CvarRegistry.hpp"

CCvarRegistry::CCvarRegistry() = default;
CCvarRegistry::~CCvarRegistry() = default;

ICvar *CCvarRegistry::Add(const char *asName, const char *asDefValue, const char *asDescription)
{
	// Check if already registered
	ICvar *pVar = Find(asName);
	
	if(pVar)
		return pVar;
	
	//return mvVars.emplace_back(asName, asDefValue, asDescription);
	ICvar *pCvar = new CCvar(asName, asDefValue, asDescription);
	mvVars.push_back(pCvar);
	return pCvar;
};

bool CCvarRegistry::Register(ICvar *apCvar)
{
	// Check if another cvar with the same name already registered
	if(Find(apCvar->GetName()))
		return false;
	
	mvVars.push_back(apCvar);
	return true;
};

ICvar *CCvarRegistry::Find(const char *asName) const
{
	for(auto It : mvVars)
		if(!strcmp(It->GetName(), asName))
			return It;
	
	return nullptr;
};

void CCvarRegistry::Remove(const char *asName)
{
	ICvar *pCvar = Find(asName);
	
	if(!pCvar)
		return;
	
	std::remove(mvVars.begin(), mvVars.end(), pCvar);
};