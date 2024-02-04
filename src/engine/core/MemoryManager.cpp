/*
 * This file is part of V-Engine
 *
 * Copyright 2018, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include <cstdlib>

#include "MemoryManager.hpp"

CMemoryManager::CMemoryManager() = default;
CMemoryManager::~CMemoryManager() = default;

void *CMemoryManager::Alloc(size_t anSize)
{
	mnTotalAllocated += anSize;
	void *pData = malloc(anSize);
	//mvAllocChunks.push_back(pData);
	return pData;
};

void CMemoryManager::Free(void *apData)
{
	if(!apData)
		return;
	
	//for(auto It : mvAllocChunks)
		//if(It->mpData == apData)
		{
			//mnTotalReleased += It->mnSize;
			free(apData); //free(It->mpData);
			apData = nullptr; //It->mpData = apData = nullptr;
		};
};

/*
const SMemStats &CMemoryManager::GetStats() const
{
	mStats.mnLeaked = mStats.mnTotalAllocated - mStats.mnTotalReleased;
	return mStats;
};
*/