#pragma once
#include "../Erbium/Module.h"

namespace Erbium {

	class ResourceManager : public Module
	{
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
