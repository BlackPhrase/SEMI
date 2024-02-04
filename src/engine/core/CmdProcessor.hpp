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

#pragma once

#include <CommonTypes.hpp>
#include <core/ICmdProcessor.hpp>

class CSysCmdRegistry;


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