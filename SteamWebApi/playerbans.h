#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "steamconst.h"

namespace steamweb
{
	struct PlayerBans_t
	{
		PlayerBans_t(nlohmann::json js)
		{
			SW_CVALUE(steamid, "SteamId");
			SW_CVALUE(communitybanned, "CommunityBanned");
			SW_CVALUE(vacbanned, "VACBanned");
			SW_CVALUE(numberofvacbans, "NumberOfVACBans");
			SW_CVALUE(dayssincelastban, "DaysSinceLastBan");
			SW_CVALUE(numberofgamebans, "NumberOfGameBans");
			SW_CVALUE(economyban, "EconomyBan");
		}

		// Blame valve for these having caps

		std::string	steamid;
		bool		communitybanned;
		bool		vacbanned;
		uint32_t	numberofvacbans;
		uint64_t	dayssincelastban;
		uint32_t	numberofgamebans;
		std::string economyban;
	};
}