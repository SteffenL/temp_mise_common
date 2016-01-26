#pragma once

#include <stdexcept>

namespace mise_common {

class IoError : public std::runtime_error
{
public:
    IoError(const std::string& message)
        : runtime_error(message)
    {
    }
};

}
