from conans import ConanFile, CMake
import os

class MiseCommonConan(ConanFile):
    name = "mise_common"
    version = "0.1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"
    requires = "Boost/1.60.0@lasote/stable"
    exports = "CMakeLists.txt", "include/*", "src/*", "thirdparty/*"

    def build(self):
        cmake = CMake(self.settings)
        print("************ cmake command line: %s" % cmake.command_line)
        # Throws error if the CMake command line contains the following: -DCONAN_COMPILER="Visual Studio"
        self.run("cmake . %s" % cmake.command_line)
        # This works:
        #self.run('cmake . -G "Visual Studio 14"')
        self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy(pattern="*.h", dst="include", src="include")

        self.copy(pattern="*.dll", dst="bin", src="bin")
        self.copy(pattern="*.lib", dst="lib", src="lib")
        self.copy(pattern="*.pdb", dst="lib", src="lib")

    def package_info(self):
        self.cpp_info.libs = ["mise_common"]
