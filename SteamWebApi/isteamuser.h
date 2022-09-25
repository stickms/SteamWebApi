#pragma once

#include "isteaminterface.h"
#include "playersummary.h"

namespace steamweb
{
	// Perhaps this should be a singleton instead
	class ISteamUser : public ISteamInterface
	{
	public:

		PlayerSummaryModel GetPlayerSummary(uint64_t steamid);
		std::vector<PlayerSummaryModel> GetPlayerSummary(std::vector<uint64_t> steamids);

	protected:

		virtual std::string GetInterfaceName() { return "ISteamUser"; }

	};

	extern ISteamUser* steamuser;
}