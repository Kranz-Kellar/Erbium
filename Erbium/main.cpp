#include <stdio.h>
#include "Engine.h"
#include "EventManager.h"
#include "ThreadPool.h"
#include "../utils/Logger.h"

using namespace std;
using namespace Erbium;

const char* Logger::logFileName = "engine.log";
mutex Logger::logMutex;
map<EventType, vector<Module*>> EventManager::subscribedModules;

void sum() {
	printf("sum1\n");
}

void sum2() {
	printf("sum2\n");
}
void sum3() {
	printf("sum3\n");
}

int main()
{
	Engine engine;
	engine.init();
	engine.initModules();

	engine.updateModules(1);

	engine.terminateModules();

	ThreadPool threadPool;
	threadPool.AddJob(sum);
	threadPool.AddJob(sum2);
	threadPool.AddJob(sum3);
	
	std::this_thread::sleep_for(chrono::milliseconds(100));
	threadPool.Terminate();
	printf("It's works!");

	return 0;
}

