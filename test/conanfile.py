from conans import ConanFile, CMake
import os

class RunConanTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"
    requires = "mise_common/0.1.0@sl/testing"

    def build(self):
        cmake = CMake(self.settings)
        print("************ cmake command line: %s" % cmake.command_line)
        # Throws error if the CMake command line contains the following: -DCONAN_COMPILER="Visual Studio"
        self.run("cmake . %s" % cmake.command_line)
        # This works:
        #self.run('cmake . -G "Visual Studio 14"')
        self.run("cmake --build . %s" % cmake.build_config)

    def imports(self):
        self.copy(pattern="*.dll", dst="bin", src="bin")

    def test(self):
        os.chdir("bin")
        self.run("run_conan_test")
