cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

project(mise_common)
set(TARGET_NAME mise_common)


#
# Third-party setup
#

set(CONANBUILDINFO_CMAKE_PATH "conanbuildinfo.cmake")

# Setup Conan
include(${CONANBUILDINFO_CMAKE_PATH})
conan_basic_setup()

#
# Setup our target
#

file(GLOB_RECURSE Sources
    "src/*.cpp"
    "thirdparty/nowide/src/*.cpp"
)

add_library(${TARGET_NAME} STATIC ${Sources})

target_include_directories(${TARGET_NAME}
    PUBLIC "include"
    PRIVATE "thirdparty/nowide"
)
