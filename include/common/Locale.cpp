#include "Locale.h"
#include <boost/locale.hpp>
#include <boost/filesystem/path.hpp>


namespace common {

void SetupLocale()
{
    std::locale::global(boost::locale::generator().generate(""));
    boost::filesystem::path::imbue(std::locale());
}

}
