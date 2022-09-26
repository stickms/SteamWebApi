#pragma once

#include "isteaminterface.h"
#include "playersummary.h"
#include "playerbans.h"
#include "playerfriend.h"
#include "vanityurl.h"

namespace steamweb
{
	// Perhaps this should be a singleton instead
	class ISteamUser : public ISteamInterface
	{
	public:

		PlayerSummary_t GetPlayerSummary(uint64_t steamid);
		std::vector<PlayerSummary_t> GetPlayerSummary(std::vector<uint64_t> steamids);

		PlayerBans_t GetPlayerBans(uint64_t steamid);
		std::vector<PlayerBans_t> GetPlayerBans(std::vector<uint64_t> steamids);

		std::vector<PlayerFriend_t> GetFriendList(uint64_t steamid, std::string_view relationship = "friend");

		std::vector<std::string> GetUserGroupList(uint64_t steamid);

		VanityURL_t ResolveVanityURL(std::string_view vanityurl, uint32_t url_type = 1);

	protected:

		virtual std::string GetInterfaceName() { return "ISteamUser"; }

	};

	extern ISteamUser* steamuser;
}