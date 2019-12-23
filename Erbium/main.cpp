#include <stdio.h>
#include "Engine.h"
#include "EventManager.h"
#include "ThreadPool.h"
#include "../utils/Logger.h"


#include "../window/GLFWWindowHandler.h"
#include "../renderer/IRenderer.h"

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

	GLFWWindowHandler* window = new GLFWWindowHandler();
	
	engine.addModule(1, window);

	engine.updateModules(1);

	engine.terminateModules();

	return 0;
}

