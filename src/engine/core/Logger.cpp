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