#pragma once
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <functional>
#include <stdio.h>
#include <chrono>
#include <iostream>
#include <atomic>
#include "../utils/Logger.h"

using namespace std;

namespace Erbium {

	class ThreadPool
	{
		vector<thread> workers;
		uint32_t maxThreadNums;
		bool workInProgress;
		mutex poolMutex;
		mutex terminateMutex;
		condition_variable condition;
		queue<function<void()>> jobs;

	public:

		ThreadPool();
		~ThreadPool();

		void InfiniteWork();

		void AddJob(function<void()> job);

		void Terminate();
	};

}

