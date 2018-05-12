/// @file

#pragma once

#include "core/IMemoryManager.hpp"

class CMemoryManager final : public IMemoryManager
{
public:
	CMemoryManager();
	~CMemoryManager();
	
	void *Alloc(size_t anSize);
	void Free(void *apData);
private:
};