/// @file

#pragma once

#include <vector>

class CCvar;
using tCvarVec = std::vector<CCvar*>;

class CCvarRegistry final : public ICvarRegistry
{
public:
	CCvarRegistry();
	~CCvarRegistry();
	
	ICvar *Register(const char *asName, const char *asDefValue, const char *asDescription) override;
	
	ICvar *Find(const char *asName) const override;
private:
	tCvarVec mvVars;
};