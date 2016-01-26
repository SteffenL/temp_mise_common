#pragma once

#include <string>

namespace mise_common {

class SteamPaths
{
public:
    SteamPaths();
    virtual ~SteamPaths();
    static std::string GetAppInstallPath(unsigned int steamId);
    static std::string GetGetGameSavePath();
};

}
