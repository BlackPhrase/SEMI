/// @file

#pragma once

#include <vector>

#include "core/ICvarRegistry.hpp"

class ICvar;
using tCvarVec = std::vector<ICvar*>;

class CCvarRegistry final : public ICvarRegistry
{
public:
	CCvarRegistry();
	~CCvarRegistry();
	
	ICvar *Add(const char *asName, const char *asDefValue, const char *asDescription) override;
	
	bool Register(ICvar *apCvar); //override;
	
	ICvar *Find(const char *asName) const override;
	
	void Remove(const char *asName) override;
private:
	tCvarVec mvVars;
};