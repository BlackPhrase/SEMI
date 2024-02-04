/*
 * This file is part of V-Engine
 *
 * Copyright 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#pragma once

#include <core/ISystem.hpp>

class CCmdArgs;
class CLogger;
class CCmdProcessor;
class CSysVarRegistry;
class CSysCmdRegistry;

class CSystem : public ISystem
{
public:
	void AddMessageSink(IMessageSink *apSink) override;
	void RemoveMessageSink(IMessageSink *apSink) override;
	
	void Quit(int anStatusCode = 0) override;
	
	bool AddCmd(const char *asName, pfnCmdCallback afnCallback, const char *asDescription) override;
	bool RegisterCmd(ISysCmd *apCmd) override;
	bool RemoveCmd(const char *asName) override;
	
	//ISysCmd *FindCmd(const char *asName) const override;
	
	ICvar *AddVar(const char *asName, const char *asDefValue, const char *asDescription) override;
	//bool RegisterVar(ISysVar *apVar) override;
	bool RemoveVar(const char *asName) override;
	
	ICvar *FindVar(const char *asName) const override;
	
	IStartupArgs *GetStartupArgs() const override {return mpStartupArgs;}
private:
	CCmdArgs *mpStartupArgs{nullptr};
	CLogger *mpLogger{nullptr};
	CCmdProcessor *mpCmdProcessor{nullptr};
	CSysVarRegistry *mpVarRegistry{nullptr};
	CSysCmdRegistry *mpCmdRegistry{nullptr};
};