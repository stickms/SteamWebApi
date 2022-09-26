#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "steamconst.h"

namespace steamweb
{
	struct PlayerBansModel
	{
		PlayerBansModel(nlohmann::json js)
		{
			SW_VALUE(SteamId);
			SW_VALUE(CommunityBanned);
			SW_VALUE(VACBanned);
			SW_VALUE(NumberOfVACBans);
			SW_VALUE(DaysSinceLastBan);
			SW_VALUE(NumberOfGameBans);
			SW_VALUE(EconomyBan);
		}

		// Blame valve for these having caps

		std::string	SteamId;
		bool		CommunityBanned;
		bool		VACBanned;
		uint32_t	NumberOfVACBans;
		uint64_t	DaysSinceLastBan;
		uint32_t	NumberOfGameBans;
		std::string EconomyBan;
	};
}