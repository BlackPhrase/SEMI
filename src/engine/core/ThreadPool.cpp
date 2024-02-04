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

#include <cstdio>
#include <thread>
#include <atomic>
#include <mutex>

#include "ThreadPool.hpp"

std::mutex mutex;

void ThreadLoop()
{
	std::this_thread::yield();
	/*
	using namespace std::chrono_literals;
	
	static std::atomic_int nLoop;
	
	while(true)
	{
		// TODO: do something
		
		if(nLoop != 100)
		{
			std::this_thread::sleep_for(1s);
			std::lock_guard<std::mutex> guard(mutex);
			printf("ThreadLoop (id #%d)\n", std::this_thread::get_id());
			++nLoop;
		};
	};
	*/
};

CThreadPool::CThreadPool(int anThreadCount)
{
	unsigned nMainThread{1};
	unsigned nHardwareConcurrency{std::thread::hardware_concurrency()};
	
	int nMaxThreads = (nHardwareConcurrency * 2) - nMainThread;
	
	if(anThreadCount == -1)
		anThreadCount = nHardwareConcurrency - nMainThread;
	
	if(anThreadCount > nMaxThreads)
		anThreadCount = nMaxThreads;
	
	if(anThreadCount < 0)
		anThreadCount = 0;
	
	for(auto i = 0; i < anThreadCount; ++i)
	{
		mvThreads.emplace_back(ThreadLoop);
		mvThreads[i].detach();
	};
	
	printf("ThreadPool: hardware concurrency is %d\n", std::thread::hardware_concurrency());
	printf("ThreadPool: %d worker thread(s) spawned\n", anThreadCount);
};

CThreadPool::~CThreadPool() = default;