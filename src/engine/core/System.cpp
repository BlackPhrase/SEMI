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

#include "System.hpp"
#include "Logger.hpp"
#include "CmdProcessor.hpp"
#include "SysVarRegistry.hpp"
#include "SysCmdRegistry.hpp"

void CSystem::AddLogSink(ILogSink *apSink)
{
	mpLogger->AddSink(apSink);
};

void CSystem::RemoveLogSink(ILogSink *apSink)
{
	mpLogger->RemoveSink(apSink);
};

bool CSystem::AddCmd(const char *asName, pfnCmdCallback afnCallback, const char *asDescription)
{
	if(mpVarRegistry->Find(asName))
	{
		Error("Can't add a system command called {} as it's already registered as a variable!", asName);
		return false;
	};
	
	return mpCmdRegistry->Add(asName, afnCallback, asDescription);
};

//bool CSystem::RegisterCmd(ISysCmd *apCmd)
//{
	//if(FindVar(apCmd->GetName())
		//return false;
	
	//return mpCmdRegistry->Register(apCmd);
//};

bool CSystem::RemoveCmd(const char *asName)
{
	return mpCmdRegistry->Remove(asName);
};

//ISysCmd *CSystem::FindCmd(const char *asName) const
//{
	//return mpCmdRegistry->Find(asName);
//};

ISysVar *CSystem::AddVar(const char *asName, const char *asDefValue, const char *asDescription)
{
	if(mpCmdRegistry->Find(asName))
	{
		Error("Can't add a system variable called {} as it's already registered as a command!", asName);
		return nullptr;
	};
	
	return mpVarRegistry->Add(asName, asDefValue, asDescription);
};

//bool CSystem::RegisterVar(ISysVar *apVar)
//{
	//if(FindCmd(apVar->GetName())
		//return false;
	
	//return mpVarRegistry->Register(apVar);
//};

bool CSystem::RemoveVar(const char *asName)
{
	return mpVarRegistry->Remove(asName);
};

ISysVar *CSystem::FindVar(const char *asName) const
{
	return mpVarRegistry->Find(asName);
};