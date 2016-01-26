#include <mise_common/Locale.h>
#include <boost/locale.hpp>
#include <boost/filesystem/path.hpp>


namespace mise_common {

void SetupLocale()
{
    std::locale::global(boost::locale::generator().generate(""));
    boost::filesystem::path::imbue(std::locale());
}

}
