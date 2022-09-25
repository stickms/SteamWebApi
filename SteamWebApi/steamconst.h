#pragma once

#include <nlohmann\json.hpp>

#define SW_VALUE(var) steamweb::GetSteamModelValue(js, #var, var)
#define SW_OPTIONAL(var, def) steamweb::GetSteamModelValue(js, #var, var, def)

#define STEAM_API_URL "http://api.steampowered.com/"

namespace steamweb
{
	template <typename T, typename K>
	inline void GetSteamModelValue(nlohmann::json js, const std::string& name, T& var, K def)
	{
		var = js.value(name, def);
	}

	template <typename T>
	inline void GetSteamModelValue(nlohmann::json js, const std::string& name, T& var)
	{
		var = js[name];
	}
}