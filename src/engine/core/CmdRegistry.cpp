/// @file

#include "CmdRegistry.hpp"

CCmdRegistry::CCmdRegistry() = default;
CCmdRegistry::~CCmdRegistry() = default;

void CCmdRegistry::Add(const char *asName, pfnCmdCallback afnCallback, const char *asDescription)
{
	SCmd *pCmd = new SCmd(asName, afnCallback, asDescription);
	mvCmds.push_back(pCmd);
};

void CCmdRegistry::Remove(const char *asName)
{
	// TODO
};

SCmd *CCmdRegistry::Find(const char *asName) const
{
	for(auto It : mvCmds)
		if(It->msName == asName)
			return It;
	
	return nullptr;
};