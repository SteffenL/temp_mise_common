#include <mise_common/SteamPaths.h>
#include <boost/filesystem.hpp>
#include <memory>
#include <mise_common/Registry.h>
#include <nowide/convert.hpp>

namespace mise_common {

SteamPaths::SteamPaths() {}

SteamPaths::~SteamPaths() {}

std::string SteamPaths::GetAppInstallPath(unsigned int steamId)
{
    using namespace mise_common;
    namespace fs = boost::filesystem;

    const std::string regPath("HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\Steam App " + std::to_string(steamId) + "\\InstallLocation");
    if (Registry::ValueExists(regPath)) {
        std::string installLocation;
        Registry::GetValue(regPath, installLocation, RegWow64Flag::_32bit);
        if (fs::is_directory(installLocation)) {
            fs::path p(installLocation);
            return p.string();
        }
    }

    return std::string();
}

std::string SteamPaths::GetGetGameSavePath()
{
    return std::string();
}

}
