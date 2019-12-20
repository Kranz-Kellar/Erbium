#pragma once
#include <pugixml/pugixml.hpp>
#include "../utils/Logger.h"

#define CONFIG_FILE "config.ini"

namespace Erbium {

	class ConfigurationManager
	{
	public:
		void LoadConfigurations();
	};

}
