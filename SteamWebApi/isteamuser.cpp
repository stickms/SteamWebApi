#include "isteamuser.h"
#include <nlohmann\json.hpp>

using namespace steamweb;

ISteamUser* steamweb::steamuser = new ISteamUser;

std::string steamids_to_string(std::vector<uint64_t> steamids)
{
	std::string idlist = std::to_string(steamids[0]);
	for (auto it = steamids.begin() + 1; it != steamids.end(); it++)
		idlist.append("," + std::to_string(*it));

	return idlist;
}

PlayerSummary_t ISteamUser::GetPlayerSummary(uint64_t steamid)
{
	nlohmann::json request = SteamWebRequest("GetPlayerSummaries", 2, { { "steamids", std::to_string(steamid) } });
	return PlayerSummary_t(request["response"]["players"][0]);
}

std::vector<PlayerSummary_t> ISteamUser::GetPlayerSummary(std::vector<uint64_t> steamids)
{
	nlohmann::json request = SteamWebRequest("GetPlayerSummaries", 2, { { "steamids", steamids_to_string(steamids) }});
	request = request["response"]["players"];
	return std::vector<PlayerSummary_t>(request.begin(), request.end());
}

PlayerBans_t ISteamUser::GetPlayerBans(uint64_t steamid)
{
	nlohmann::json request = SteamWebRequest("GetPlayerBans", 1, { { "steamids", std::to_string(steamid) } });
	return PlayerBans_t(request["players"][0]);
}

std::vector<PlayerBans_t> ISteamUser::GetPlayerBans(std::vector<uint64_t> steamids)
{
	nlohmann::json request = SteamWebRequest("GetPlayerBans", 1, { { "steamids", steamids_to_string(steamids) } });
	request = request["players"];
	return std::vector<PlayerBans_t>(request.begin(), request.end());
}

std::vector<PlayerFriend_t> ISteamUser::GetFriendList(uint64_t steamid, std::string_view relationship)
{
	nlohmann::json request = SteamWebRequest("GetFriendList", 1, {	{ "steamid", std::to_string(steamid) }, 
																	{ "relationship", relationship.data() } });
	request = request["friendslist"]["friends"];
	return std::vector<PlayerFriend_t>(request.begin(), request.end());
}

std::vector<std::string> ISteamUser::GetUserGroupList(uint64_t steamid)
{
	nlohmann::json request = SteamWebRequest("GetUserGroupList", 1, { { "steamid", std::to_string(steamid) } });
	std::vector<std::string> result = {};

	for (auto& gid : request["response"]["groups"])
		result.push_back(gid.value("gid", ""));

	return result;
}

VanityURL_t ISteamUser::ResolveVanityURL(std::string_view vanityurl, uint32_t url_type)
{
	nlohmann::json request = SteamWebRequest("ResolveVanityURL", 1, {	{ "vanityurl", vanityurl.data() },
																		{ "url_type", std::to_string(url_type) } });
	return VanityURL_t(request["response"]);
}