#include <iostream>
#include <sstream>
#include <curlpp\cURLpp.hpp>
#include <curlpp\Options.hpp>
#include <curlpp\Easy.hpp>
#include "isteamuser.h"

int main()
{
    // Example usage
    steamweb::setapikey("API-KEY-HERE"); 
    
    auto result = steamweb::steamuser->GetPlayerSummary(76561197960287930);

    std::cout << result.personaname << std::endl;
}