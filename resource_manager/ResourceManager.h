#pragma once
#include "../Erbium/Module.h"
#include "../utils/Logger.h"
#include <map>
#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

namespace Erbium {

	class ResourceManager : public Module
	{
		/*
			Scan res directory and load all resource files
		*/
		void scanAndLoadResources();
		void releaseResources();

	public:
		ResourceManager();
		~ResourceManager();

		void init() override;
		void update(uint32_t deltaTime) override;
		void disable() override;
		void terminate() override;

		void onEvent(Event* event) override;

	};

}
