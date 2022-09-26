#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <nlohmann/json.hpp>

namespace steamweb
{
	extern void setapikey(const std::string& key);

	class ISteamInterface
	{
	protected:

		virtual std::string GetInterfaceName() = 0;

		// Should be cast to the appropriate model
		nlohmann::json SteamWebRequest(	const std::string& name, uint16_t version,
										std::vector<std::pair<std::string, std::string>> data = {} );
	};
}