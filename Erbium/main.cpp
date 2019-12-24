#include <stdio.h>
#include "Engine.h"
#include "EventManager.h"
#include "ThreadPool.h"
#include "ConfigurationManager.h"
#include "../utils/Logger.h"

using namespace std;
using namespace Erbium;

const char* Logger::logFileName = "engine.log";
mutex Logger::logMutex;
map<EventType, vector<Module*>> EventManager::subscribedModules;

int main()
{
	Engine engine;
	engine.init();
	engine.initModules();

	engine.updateModules(1);

	engine.terminateModules();


	ConfigurationManager configManager;
	configManager.LoadConfigurations();
	

	return 0;
}

/*
	Module -> Erbium
	Erbium !-> Module
*/