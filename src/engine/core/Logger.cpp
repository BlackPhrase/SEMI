/*
 * This file is part of V-Engine
 *
 * Copyright 2018-2019, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include <cstdarg>
#include <cstdio>

#include "Logger.hpp"

CLogger::CLogger() = default;
CLogger::~CLogger() = default;

void CLogger::AddSink(ILogSink *apSink)
{
	mlstSinks.push_back(apSink);
};

void CLogger::RemoveSink(ILogSink *apSink)
{
	//mlstSinks. // TODO
};

void CLogger::Message(const char *asMsg, ...)
{
	va_list lstArgs;
	char sFormatted[256]{};
	
	va_start(lstArgs, asMsg);
	vsprintf(sFormatted, asMsg, lstArgs);
	va_end(lstArgs);
	
	for(auto It : mlstSinks)
		It->OnMessage(sFormatted);
};