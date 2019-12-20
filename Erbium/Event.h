#pragma once
#include "EventType.h"

namespace Erbium {
	class Event
	{
	public:
		EventType type;
		Event();
		virtual ~Event();
	};
}
