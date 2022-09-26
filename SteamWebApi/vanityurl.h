#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "steamconst.h"

namespace steamweb
{
	struct VanityURL_t
	{
		VanityURL_t(nlohmann::json js)
		{
			SW_VALUE(success);
			SW_VALUE(steamid);
			SW_VALUE(message);
		}

		// 1 = found a profile, other numbers indicate not a success
		uint32_t success;
		std::string steamid;

		// Filled only if not a successfull resolve
		std::string message;
	};
}