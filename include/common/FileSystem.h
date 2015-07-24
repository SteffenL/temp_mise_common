#pragma once

#if 0
// VC++
#ifdef _MSC_VER

#if _MSC_VER < 1700 // Earlier than VS 2012

#include <boost/filesystem.hpp>

namespace common { namespace filesystem {
    using namespace boost::filesystem;
}}

#elif _MSC_VER < 1900 // Earlier than VS 2015

#include <filesystem>

namespace common { namespace filesystem {
    using namespace std::tr2::sys;
}}

#else
#error Support for the filesystem header has not been implemented VS 2015 and later
#endif

#else
#error Support for the filesystem header has not been implemented
#endif
#endif

// For now, always use boost because we need UTF-8 support for paths, and there appears to be no such thing in VC++ 2013
#include <boost/filesystem.hpp>

namespace common { namespace filesystem {
    using namespace boost::filesystem;
}}
