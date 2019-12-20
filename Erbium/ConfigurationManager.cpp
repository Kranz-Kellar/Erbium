#include "ConfigurationManager.h"

void Erbium::ConfigurationManager::LoadConfigurations()
{
	pugi::xml_document document;
	pugi::xml_parse_result result = document.load_file(CONFIG_FILE);
	if (!result) {
		Logger::Log(LOG_CRITICAL, "Config file not found");
		return;
	}

}
