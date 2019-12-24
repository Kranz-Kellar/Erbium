#pragma once
#include <stdint.h>
#include "ModuleType.h"
#include "Event.h"

namespace Erbium {

	class Module
	{
	protected:
		ModuleType type;
		bool isDisabled;
	public:
		Module() : type(MODULE_NONE), isDisabled(false) {}
		virtual ~Module() {}

		void virtual init() = 0;
		void virtual update(uint32_t deltaTime) = 0;
		void virtual disable() = 0;
		void virtual terminate() = 0;

		void virtual onEvent(Event* event) = 0;
		void virtual invokeEvent(Event* event);
		void virtual subscribeOnEventType(EventType type);
		void virtual unsubscribeFromEventType(EventType type);
	};

}
