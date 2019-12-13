#pragma once
#include "Event.h"
#include <stdint.h>

class Module
{

public:
	Module() {}
	virtual ~Module() {}

	void virtual init() = 0;
	void virtual update(uint32_t deltaTime) = 0;
	void virtual disable() = 0;
	void virtual terminate() = 0;

	void virtual invokeEvent(Event* event) = 0;
	void virtual onEvent(Event* event) = 0;
};

