#include "ThreadPool.h"

Erbium::ThreadPool::ThreadPool()
{
	maxThreadNums = thread::hardware_concurrency();
	workInProgress = true;
	for (uint32_t i = 0; i < maxThreadNums; i++) {
		workers.push_back(thread(&ThreadPool::InfiniteWork, this));
	}
}

Erbium::ThreadPool::~ThreadPool()
{
}

void Erbium::ThreadPool::InfiniteWork()
{
	while (workInProgress) {
		printf("Waiting for job!\n");
		unique_lock<mutex> lock(poolMutex);
		if (!jobs.empty()) {
			auto job = jobs.front();
			jobs.pop();
			job();
			printf("Job complete!\n");
		}
		else {
			std::this_thread::sleep_for(chrono::milliseconds(1));
			printf("End of waiting!\n");
		}
	}
}

void Erbium::ThreadPool::AddJob(function<void()> job)
{
	unique_lock<mutex> lock(poolMutex);
	jobs.push(job);
	condition.notify_one();
}

void Erbium::ThreadPool::Terminate()
{
	{
		unique_lock<mutex> lock(terminateMutex);
		workInProgress = false;
		condition.notify_all();
	}
	for (thread& worker : workers) {
		if (worker.joinable()) {
			worker.join();
		}
	}

	workers.empty();
}
