/// @file
/// @brief command processor interface

#pragma once

struct ICmdProcessor
{
	///
	virtual void InsertText(const char *asText) = 0;
	
	///
	virtual void AppendText(const char *asText) = 0;
	
	///
	virtual void ExecText(const char *asText) = 0;
	
	///
	virtual void ExecPending() = 0;
};