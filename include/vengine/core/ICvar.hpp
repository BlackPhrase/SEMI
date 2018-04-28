/// @file
/// @brief console variable

#pragma once

struct ICvar
{
	///
	virtual const char *GetName() const = 0;
	
	///
	virtual const char *GetDescription() const = 0;
	
	///
	virtual void SetValue(const char *asValue) = 0;
	
	///
	virtual const char *GetValue() const = 0;
};