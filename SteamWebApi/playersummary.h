#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "steamconst.h"

namespace steamweb
{
	struct PlayerSummaryModel
	{
		// We have to deserialize this stuff manually (C++ moment)
		PlayerSummaryModel(nlohmann::json js)
		{
			SW_VALUE(steamid);
			SW_VALUE(personaname);
			SW_VALUE(profileurl);
			SW_VALUE(avatar);
			SW_VALUE(avatarmedium);
			SW_VALUE(avatarfull);
			SW_VALUE(personastate);
			SW_VALUE(communityvisibilitystate);
			SW_VALUE(profilestate);
			SW_VALUE(commentpermission);

			SW_OPTIONAL(realname, "");
			SW_OPTIONAL(primaryclanid, "0");
			SW_OPTIONAL(timecreated, 0);
			SW_OPTIONAL(lastlogoff, 0);
			SW_OPTIONAL(gameid, "0");
			SW_OPTIONAL(gameserverip, "0.0.0.0:0");
			SW_OPTIONAL(gameextrainfo, "");
			SW_OPTIONAL(loccountrycode, "");
			SW_OPTIONAL(locstatecode, "");
			SW_OPTIONAL(loccityid, "");
		}

		// Public Data (never null/unknown)

		std::string	steamid;
		std::string	personaname;
		std::string	profileurl;
		std::string	avatar;
		std::string	avatarmedium;
		std::string	avatarfull;
		short		personastate;
		short		communityvisibilitystate;
		short		profilestate;
		short		commentpermission;

		// Private Data (may not be filled depending on visibility state)

		std::string	realname;
		std::string	primaryclanid;
		uint64_t	timecreated;
		uint64_t	lastlogoff;
		std::string	gameid;
		std::string	gameserverip;
		std::string	gameextrainfo;
		std::string	loccountrycode;
		std::string	locstatecode;
		std::string loccityid;
	};
}