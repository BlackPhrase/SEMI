/// @file
/// @brief command line interface

#pragma once

struct ICommandLine
{
	///
	virtual bool HasArg(const char *asName) const = 0;
	
	///
	virtual const char *GetArgByName(const char *asName) const = 0;
	
	///
	virtual const char *GetArgByIndex(int anIndex) const = 0;
};