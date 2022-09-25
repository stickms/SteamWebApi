#include "isteamuser.h"
#include <nlohmann\json.hpp>

using namespace steamweb;

ISteamUser* steamweb::steamuser = new ISteamUser;

PlayerSummaryModel ISteamUser::GetPlayerSummary(uint64_t steamid)
{
	nlohmann::json request = SteamWebRequest("GetPlayerSummaries", "v0002", { { "steamids", std::to_string(steamid) } });
	return PlayerSummaryModel(request["response"]["players"][0]);
}

std::vector<PlayerSummaryModel> ISteamUser::GetPlayerSummary(std::vector<uint64_t> steamids)
{
	std::string idlist = { };
	for (auto& id : steamids)
	{
		if (&id != &steamids[0])
			idlist.append(",");
		idlist.append(std::to_string(id));
	}

	nlohmann::json request = SteamWebRequest("GetPlayerSummaries", "v0002", { { "steamids", idlist } });
	request = request["response"]["players"];

	std::vector<PlayerSummaryModel> result = {};

	for (size_t i = 0; i < request.size(); i++)
		result.push_back(PlayerSummaryModel(request[i]));

	return result;
}