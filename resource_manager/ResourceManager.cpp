#include "ResourceManager.h"

void Erbium::ResourceManager::scanAndLoadResources()
{
	std::string path = ""; //get path from config manager
	for (const auto& entry : fs::directory_iterator(path)) {
		std::cout << entry.path() << std::endl;
		std::cout << entry.file_size() << std::endl;
	}
}

void Erbium::ResourceManager::releaseResources()
{
}

Erbium::ResourceManager::ResourceManager()
{
}

Erbium::ResourceManager::~ResourceManager()
{
}

void Erbium::ResourceManager::init()
{
	this->scanAndLoadResources();
}

void Erbium::ResourceManager::update(uint32_t deltaTime)
{
}

void Erbium::ResourceManager::disable()
{
}

void Erbium::ResourceManager::terminate()
{
	this->releaseResources();
}

void Erbium::ResourceManager::onEvent(Event* event)
{
}
