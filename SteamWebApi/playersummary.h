#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "steamconst.h"

namespace steamweb
{
	struct PlayerSummary_t
	{
		// We have to deserialize this stuff manually (C++ moment)
		PlayerSummary_t(nlohmann::json js)
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

			SW_VALUE(realname);
			SW_VALUE(primaryclanid);
			SW_VALUE(timecreated);
			SW_VALUE(lastlogoff);
			SW_VALUE(gameid);
			SW_VALUE(gameserverip);
			SW_VALUE(gameextrainfo);
			SW_VALUE(loccountrycode);
			SW_VALUE(locstatecode);
			SW_VALUE(loccityid);
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