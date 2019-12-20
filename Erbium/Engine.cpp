#include "Engine.h"

using namespace Erbium;

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::init()
{
	//Adding modules here
}

void Engine::addModule(uint32_t moduleNum, Module* new_module)
{
	this->modules[moduleNum] = new_module;
}

Module* Engine::getModule(uint32_t moduleNum)
{
	if (this->modules[moduleNum] != nullptr) {
		return modules[moduleNum];
	}
	return nullptr;
}

void Engine::disableModule(uint32_t moduleNum)
{
	modules[moduleNum]->disable();
}

void Engine::terminateModule(uint32_t moduleNum)
{
	modules[moduleNum]->terminate();
}

void Engine::initModules()
{
	for (std::map<uint32_t, Module*>::iterator it = modules.begin();
		it != modules.end(); ++it) {
		it->second->init();
	}
}

void Engine::updateModules(uint32_t deltaTime)
{
	for (std::map<uint32_t, Module*>::iterator it = modules.begin();
		it != modules.end(); ++it) {
		it->second->update(deltaTime);
	}
}

void Engine::terminateModules()
{
	for (std::map<uint32_t, Module*>::iterator it = modules.begin();
		it != modules.end(); ++it) {
		it->second->terminate();
	}
}
