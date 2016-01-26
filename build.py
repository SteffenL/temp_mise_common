import platform
import os


def system(command):
    retcode = os.system(command)
    if retcode != 0:
        raise Exception("Error while executing:\n\t %s" % command)


if __name__ == "__main__":
    system("conan export sl/testing")

    if platform.system() == "Windows":
        system('conan test -s compiler="Visual Studio" -s compiler.version=14 -s build_type=Debug -s compiler.runtime=MDd')
        system('conan test -s compiler="Visual Studio" -s compiler.version=14 -s build_type=Release -s compiler.runtime=MD')
    else:
        raise Exception("Unsupported platform")
