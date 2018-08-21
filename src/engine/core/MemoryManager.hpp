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
	size_t mnTotalAllocated{0}; ///< Total amount of allocated memory
	size_t mnTotalReleased{0}; ///< Total amount of released memory
	size_t mnLeaked{0}; ///< Amount of leaked memory (= mnTotalAllocated - mnTotalReleased)
};