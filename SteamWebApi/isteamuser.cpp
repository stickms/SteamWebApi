#include "isteamuser.h"
#include <nlohmann\json.hpp>
#include <Windows.h>

using namespace steamweb;

ISteamUser* steamweb::steamuser = new ISteamUser;

std::string steamids_to_string(std::vector<uint64_t> steamids)
{
	std::string idlist = std::to_string(steamids[0]);
	for (auto it = steamids.begin() + 1; it != steamids.end(); it++)
		idlist.append("," + std::to_string(*it));

	return idlist;
}

PlayerSummaryModel ISteamUser::GetPlayerSummary(uint64_t steamid)
{
	nlohmann::json request = SteamWebRequest("GetPlayerSummaries", 2, { { "steamids", std::to_string(steamid) } });
	return PlayerSummaryModel(request["response"]["players"][0]);
}

std::vector<PlayerSummaryModel> ISteamUser::GetPlayerSummary(std::vector<uint64_t> steamids)
{
	nlohmann::json request = SteamWebRequest("GetPlayerSummaries", 2, { { "steamids", steamids_to_string(steamids) }});
	request = request["response"]["players"];
	return std::vector<PlayerSummaryModel>(request.begin(), request.end());
}

PlayerBansModel ISteamUser::GetPlayerBans(uint64_t steamid)
{
	nlohmann::json request = SteamWebRequest("GetPlayerBans", 1, { { "steamids", std::to_string(steamid) } });
	return PlayerBansModel(request["players"][0]);
}

std::vector<PlayerBansModel> ISteamUser::GetPlayerBans(std::vector<uint64_t> steamids)
{
	nlohmann::json request = SteamWebRequest("GetPlayerBans", 1, { { "steamids", steamids_to_string(steamids) }});
	request = request["players"];
	return std::vector<PlayerBansModel>(request.begin(), request.end());
}