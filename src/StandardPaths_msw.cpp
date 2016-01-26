#ifdef _WIN32

#include <mise_common/StandardPaths.h>
#include <nowide/convert.hpp>

#include <Windows.h>
#include <vector>

namespace mise_common {

std::string StandardPaths::GetExecutablePath() {
    std::vector<wchar_t> buffer;
    unsigned int bufferLength = MAX_PATH;
    buffer.resize(bufferLength);

    bool isOk = false;

    do {
        DWORD requiredLength = ::GetModuleFileNameW(NULL, &buffer[0], buffer.size());

        // Failed?
        /*if (requiredLength == 0) {
            throw WindowsException(::GetLastError());
        }*/

        // If the returned module path was truncated, we need a larger buffer
        if (requiredLength >= bufferLength) {
            // Increase buffer length
            bufferLength <<= 1;
            buffer.resize(bufferLength);
        }

        isOk = true;
    } while (!isOk);

    std::string path;
    path = nowide::narrow(&buffer[0]);
    
    return path;
}

}

#endif
