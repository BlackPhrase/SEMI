/// @file

#pragma once

#include <vector>

#include "CommonTypes.hpp"
#include "core/ICmdRegistry.hpp"

struct SCmd
{
	SCmd(const tString &asName, pfnCmdCallback afnCallback, const char *asDescription = "")
		: msName(asName), mfnCallback(afnCallback), msDesc(asDescription){}
	
	void Exec(const ICmdArgs &apArgs)
	{
		if(mfnCallback)
			mfnCallback(apArgs);
	};
	
	tString msName{""};
	tString msDesc{""};
	
	pfnCmdCallback mfnCallback{nullptr};
};

using tCmdVec = std::vector<SCmd*>;

class CCmdRegistry final : public ICmdRegistry
{
public:
	CCmdRegistry();
	~CCmdRegistry();
	
	void Add(const char *asName, pfnCmdCallback afnCallback, const char *asDescription) override;
	void Remove(const char *asName) override;
	
	SCmd *Find(const char *asName) const;
private:
	tCmdVec mvCmds;
};