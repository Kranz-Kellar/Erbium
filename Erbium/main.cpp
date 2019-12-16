#include <stdio.h>
#include "Engine.h"
#include "EventManager.h"
#include "../utils/Logger.h"

using namespace std;

const char* Logger::logFileName = "engine.log";
map<EventType, vector<Module*>> EventManager::subscribedModules;

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


	return 0;
}