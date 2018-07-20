/// @file

#pragma once

#include <list>

#include "core/ILogger.hpp"

using tLogSinkList = std::list<ILogSink*>;

class CLogger final : public ILogger
{
public:
	CLogger();
	~CLogger();
	
	void AddSink(ILogSink *apSink) override;
	void RemoveSink(ILogSink *apSink) override;
	
	void Message(const char *asMsg, ...) override;
private:
	tLogSinkList mlstSinks;
};