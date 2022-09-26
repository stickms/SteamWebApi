#pragma once

#include <nlohmann\json.hpp>
#include <string_view>

#define SW_VALUE(var) steamweb::GetSteamModelValue(js, #var, var)
#define SW_CVALUE(var, name) steamweb::GetSteamModelValue(js, name, var)

#define STEAM_API_URL "http://api.steampowered.com/"

namespace steamweb
{
	template <typename T>
	inline void GetSteamModelValue(nlohmann::json js, std::string_view name, T& var)
	{
		// If value is note found (private attr.) then call default constructor
		var = js.value(name.data(), T());
	}
}