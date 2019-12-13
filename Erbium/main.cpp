#include <stdio.h>
#include "Engine.h"

int main()
{
	Engine engine;
	engine.init();
	engine.initModules();

	engine.updateModules(1);

	engine.terminateModules();
	return 0;
}