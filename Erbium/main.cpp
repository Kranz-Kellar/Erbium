#include <stdio.h>
#include "Engine.h"
#include "EventManager.h"
#include "ThreadPool.h"
#include "../utils/Logger.h"

using namespace std;
using namespace Erbium;

const char* Logger::logFileName = "engine.log";
map<EventType, vector<Module*>> EventManager::subscribedModules;

void sum() {
	printf("sum1");
	Logger::Log(LOG_DEBUG, "sum1");
}

void sum2() {
	printf("sum2");
	Logger::Log(LOG_DEBUG, "sum2");
}
void sum3() {
	printf("sum3");
	Logger::Log(LOG_DEBUG, "sum3");
}

int main()
{
	Engine engine;
	engine.init();
	engine.initModules();

	engine.updateModules(1);

	engine.terminateModules();

	Logger::Log(LOG_INFO, "Logging info...");
	Logger::Log(LOG_CRITICAL, "Logging critical...");
	Logger::Log(LOG_DEBUG, "Logging debug...");
	Logger::Log(LOG_ERROR, "Logging error...");
	Logger::Log(LOG_WARNING, "Logging warning...");


	ThreadPool threadPool;
	threadPool.AddJob(sum);
	threadPool.AddJob(sum2);
	threadPool.AddJob(sum3);
	threadPool.AddJob(sum);
	threadPool.AddJob(sum2);
	threadPool.AddJob(sum3);
	threadPool.AddJob(sum);
	threadPool.AddJob(sum2);
	threadPool.AddJob(sum3);

	threadPool.Terminate();

	return 0;
}

