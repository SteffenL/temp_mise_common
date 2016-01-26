from conans import ConanFile, CMake
import os

class RunConanTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"
    requires = "mise_common/0.1.0@sl/testing"

    def build(self):
        cmake = CMake(self.settings)
        if not os.path.exists("build"):
            os.mkdir("build")
        os.chdir("build")
        self.run('cmake "%s" %s' % (self.conanfile_directory, cmake.command_line))
        self.run("cmake --build . %s" % cmake.build_config)

    def imports(self):
        self.copy(pattern="*.dll", dst="bin", src="bin")

    def test(self):
        os.chdir("bin")
        self.run("run_conan_test")
