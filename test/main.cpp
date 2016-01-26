#include <mise_common/StandardPaths.h>
#include <iostream>

int main()
{
    std::cout << "EXE path: " << StandardPaths::GetExecutablePath() << "\n";
    std::cout << "Test OK.\n";
    return 0;
}
