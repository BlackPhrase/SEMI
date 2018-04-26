/// @file

#include "ThreadPool.hpp"

void ThreadLoop()
{
	while(true)
	{
		// TODO: do something
	};
};

CThreadPool::CThreadPool(int anThreadCount)
{
	if(anThreadCount == -1)
		anThreadCount = std::thread::hardware_concurrency() - 1;
	
	if(anThreadCount < 0)
		anThreadCount = 0;
	
	for(auto i = 0; i < anThreadCount; ++i)
	{
		mvThreads.emplace_back(ThreadLoop);
		//mvThreads[i].detach();
	};
};

CThreadPool::~CThreadPool() = default;