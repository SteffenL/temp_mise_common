cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

project(mise_common_conan_test)
set(TARGET_NAME run_conan_test)


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

add_executable(${TARGET_NAME} main.cpp)


#
# Third-party includes/libraries
#

target_link_libraries(${TARGET_NAME} ${CONAN_LIBS})
