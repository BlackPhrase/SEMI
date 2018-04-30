/// @file

#pragma once

#include <thread>
#include <vector>

using tThreadVec = std::vector<std::thread>;

class CThreadPool
{
public:
	/// -1 means default value = hardware concurrency - 1 (main thread)
	/// max thread count = (hardware concurrency * 2) - 1 (main thread)
	CThreadPool(int anThreadCount = -1);
	~CThreadPool();
private:
	tThreadVec mvThreads;
};