#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "steamconst.h"

namespace steamweb
{
	struct PlayerFriend_t
	{
		PlayerFriend_t(nlohmann::json js)
		{
			SW_VALUE(steamid);
			SW_VALUE(relationship);
			SW_CVALUE(friendsince, "friend_since");
		}

		std::string	steamid;
		std::string relationship;
		uint64_t	friendsince;
	};
}