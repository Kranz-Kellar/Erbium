#pragma once
#include <map>
#include <stdint.h>
#include "Module.h"


namespace Erbium {

	class Engine
	{
		std::map<uint32_t, Module*> modules;

	public:
		Engine();
		~Engine();

		void init();

		void addModule(uint32_t moduleNum, Module* new_module);
		Module* getModule(uint32_t moduleNum);
		void disableModule(uint32_t moduleNum);
		void terminateModule(uint32_t moduleNum);

		void initModules();
		void updateModules(uint32_t deltaTime);
		void terminateModules();
	};

}
