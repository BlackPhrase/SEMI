/// @file

#include <cstdio>

#include "CmdProcessor.hpp"
#include "CmdRegistry.hpp"
#include "CmdArgs.hpp"

CCmdProcessor::CCmdProcessor(CCmdRegistry *apCmdRegistry) : mpCmdRegistry(apCmdRegistry){}
CCmdProcessor::~CCmdProcessor() = default;

void CCmdProcessor::InsertText(const char *asText)
{
	mCmdQue.emplace_front(asText);
};

void CCmdProcessor::AppendText(const char *asText)
{
	mCmdQue.emplace_back(asText);
};

void CCmdProcessor::ExecText(const char *asText)
{
	CCmdArgs Args(asText);
	
	auto pCmd{mpCmdRegistry->Find(Args.GetByIndex(0))};
	
	if(pCmd)
	{
		pCmd->Exec(Args);
		return;
	};
	
	printf("Unknown command: \"%s\"\n", Args.GetByIndex(0));
};

void CCmdProcessor::ExecPending()
{
	if(mCmdQue.empty())
		return;
	
	while(!mCmdQue.empty())
	{
		auto CurrentCmd{mCmdQue.front()};
		ExecText(CurrentCmd.c_str());
		mCmdQue.pop_front();
	};
};