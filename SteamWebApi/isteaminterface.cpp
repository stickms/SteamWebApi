#include "isteaminterface.h"
#include "steamconst.h"
#include <curlpp\cURLpp.hpp>
#include <curlpp\Options.hpp>
#include <curlpp\Easy.hpp>
#include <sstream>

using namespace steamweb;

std::string apikey = "";

void steamweb::setapikey(const std::string& key)
{
    apikey = key;
}

nlohmann::json ISteamInterface::SteamWebRequest(const std::string& name, uint16_t version,
                                                std::vector<std::pair<std::string, std::string>> data)
{
    std::string url = STEAM_API_URL;
    url.append(GetInterfaceName() + "/");
    url.append(name + "/v" + std::to_string(version));
    url.append("/?key=" + apikey);

    for (auto& tag : data)
        url.append("&" + tag.first + "=" + tag.second);

    curlpp::Easy req;
    std::ostringstream stream;

    req.setOpt<curlpp::options::Url>(url);
    req.setOpt<curlpp::options::WriteStream>(&stream);
    req.perform();

    return nlohmann::json::parse(stream.str());
}