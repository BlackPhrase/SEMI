/// @file
/// @brief memory pool interface

#pragma once

struct IMemoryPool
{
	///
	virtual void *Alloc(size_t anSize, const char *asFile, const char *asLine) = 0;
	
	///
	virtual void Free(void *apData, const char *asFile, const char *asLine) = 0;
};