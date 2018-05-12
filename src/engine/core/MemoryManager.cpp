/// @file

#include <cstdlib>

#include "MemoryManager.hpp"

CMemoryManager::CMemoryManager() = default;
CMemoryManager::~CMemoryManager() = default;

void *CMemoryManager::Alloc(size_t anSize)
{
	return malloc(anSize);
};

void CMemoryManager::Free(void *apData)
{
	if(apData)
	{
		free(apData);
		apData = nullptr;
	};
};