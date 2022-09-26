#pragma once

#include <nlohmann\json.hpp>

#define SW_VALUE(var) steamweb::GetSteamModelValue(js, #var, var)

#define STEAM_API_URL "http://api.steampowered.com/"

namespace steamweb
{
	template <typename T>
	inline void GetSteamModelValue(nlohmann::json js, const std::string& name, T& var)
	{
		// If value is note found (private attr.) then call default constructor
		var = js.value(name, T());
	}
}