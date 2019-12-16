#include "Module.h"
#include "EventManager.h"

using namespace Erbium;

void Module::invokeEvent(Event* event)
{
	EventManager::InvokeEvent(event);
}

void Module::subscribeOnEventType(EventType type)
{
	EventManager::SubscribeModuleOnEventType(type, this);
}

void Module::unsubscribeFromEventType(EventType type)
{
	EventManager::UnsubscribeModuleFromEventType(type, this);
}
