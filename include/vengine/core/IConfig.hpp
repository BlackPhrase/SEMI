/// @file
/// @brief config interface

#pragma once

struct IConfig
{
	///
	virtual void SetString(const char *asKey, const char *asValue) = 0;
	//virtual void SetString(const char *asSection, const char *asKey, const char *asValue) = 0;
	
	///
	virtual const char *GetString(const char *asKey) const = 0;
};