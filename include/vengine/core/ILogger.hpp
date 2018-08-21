/// @file
/// @brief logger interface

#pragma once

struct ILogSink
{
	///
	virtual void OnMessage(const char *asMsg) = 0;
};

struct ILogger
{
	///
	virtual void AddSink(ILogSink *apSink) = 0;
	
	///
	virtual void RemoveSink(ILogSink *apSink) = 0;
	
	///
	virtual void Message(const char *asMsg, ...) = 0;
};