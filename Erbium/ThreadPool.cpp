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
		unique_lock<mutex> lock(poolMutex);
		Logger::Log(LOG_DEBUG, "Waiting Job");
		condition.wait(lock, [this] {return jobs.empty() || workInProgress; });
		auto job = jobs.front();
		jobs.pop();
		printf("Doing some job");
		Logger::Log(LOG_DEBUG, "Doing some job");
		job();
		Logger::Log(LOG_DEBUG, "Job complete!");
	}
}

void Erbium::ThreadPool::AddJob(function<void()> job)
{
	unique_lock<mutex> lock(poolMutex);
	jobs.push(job);
	condition.notify_one();
	Logger::Log(LOG_DEBUG, "Job added");
}

void Erbium::ThreadPool::Terminate()
{
	unique_lock<mutex> lock(poolMutex);
	workInProgress = false;

	condition.notify_all();

	for (thread& worker : workers) {
		worker.join();
	}
	workers.empty();
}
