/// @file

#pragma once

#include <deque>
#include <string>

#include "core/ICmdProcessor.hpp"

class CCmdRegistry;

using tStringDeque = std::deque<std::string>;

class CCmdProcessor final : public ICmdProcessor
{
public:
	CCmdProcessor(CCmdRegistry *apCmdRegistry);
	~CCmdProcessor();
	
	void InsertText(const char *asText) override;
	void AppendText(const char *asText) override;
	
	void ExecText(const char *asText) override;
	void ExecPending() override;
private:
	tStringDeque mCmdQue;
	
	CCmdRegistry *mpCmdRegistry{nullptr};
};