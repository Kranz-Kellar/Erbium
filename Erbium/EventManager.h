#pragma once
#include <map>
#include <vector>
#include "Event.h"
#include "Module.h"

using namespace std;


class EventManager
{
	static map<EventType, vector<Module*>> subscribedModules;
public:

	static void InvokeEvent(Event* event) {
		auto modulesToInvoke = subscribedModules[event->type];
		for (uint32_t i = 0; i < modulesToInvoke.size(); i++) {
			modulesToInvoke[i]->onEvent(event);
		}
	}

	static void SubscribeModuleOnEventType(EventType type, Module* module) {
		subscribedModules[type].push_back(module);
	}

	static void UnsubscribeModuleFromEventType(EventType type, Module* module) {
		//No imp
	}

};

