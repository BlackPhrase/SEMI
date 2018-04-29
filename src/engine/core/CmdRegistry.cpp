/// @file

#include "CmdRegistry.hpp"

CCmdRegistry::CCmdRegistry() = default;
CCmdRegistry::~CCmdRegistry() = default;

void CCmdRegistry::Register(const char *asName, pfnCmdCallback afnCallback, const char *asDescription)
{
	SCmd *pCmd = new SCmd(asName, afnCallback, asDescription);
	mvCmds.push_back(pCmd);
};