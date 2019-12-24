#include "Engine.h"

#include "../window/GLFWWindowHandler.cpp"

Erbium::Engine::Engine()
{
}

Erbium::Engine::~Engine()
{
}

void Erbium::Engine::init()
{
	GLFWWindowHandler* windowHandler = new GLFWWindowHandler();
	this->addModule(MODULE_WINDOW, windowHandler);
}

void Erbium::Engine::addModule(uint32_t moduleNum, Module* new_module)
{
	this->modules[moduleNum] = new_module;
}

Erbium::Module* Erbium::Engine::getModule(uint32_t moduleNum)
{
	if (this->modules[moduleNum] != nullptr) {
		return modules[moduleNum];
	}
	return nullptr;
}

void Erbium::Engine::disableModule(uint32_t moduleNum)
{
	modules[moduleNum]->disable();
}

void Erbium::Engine::terminateModule(uint32_t moduleNum)
{
	modules[moduleNum]->terminate();
}

void Erbium::Engine::initModules()
{
	for (std::map<uint32_t, Module*>::iterator it = modules.begin();
		it != modules.end(); ++it) {
		it->second->init();
	}
}

void Erbium::Engine::updateModules(uint32_t deltaTime)
{
	for (std::map<uint32_t, Module*>::iterator it = modules.begin();
		it != modules.end(); ++it) {
		it->second->update(deltaTime);
	}
}

void Erbium::Engine::terminateModules()
{
	for (std::map<uint32_t, Module*>::iterator it = modules.begin();
		it != modules.end(); ++it) {
		it->second->terminate();
	}
}
