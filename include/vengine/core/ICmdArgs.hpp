/// @file
/// @brief command arguments interface

#pragma once

struct ICmdArgs
{
	///
	virtual int GetCount() const = 0;
	
	///
	virtual const char *GetByIndex(int anIndex) const = 0;
	
	///
	virtual const char *ToString() const = 0;
};