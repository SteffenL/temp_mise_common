cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

project(mise_common_conan_test)
set(TARGET_NAME run_conan_test)


#
# Third-party setup
#

set(USE_CONAN 0)
set(CONANBUILDINFO_CMAKE_PATH "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
if(EXISTS ${CONANBUILDINFO_CMAKE_PATH})
    set(USE_CONAN 1)

    # Setup Conan
    include(${CONANBUILDINFO_CMAKE_PATH})
    conan_basic_setup()
else()
    # Setup Boost
    if(NOT DEFINED ENV{BOOST_PATH})
        message(FATAL_ERROR "BOOST_PATH environment variable is not defined.")
    endif()

    set(BOOST_PATH $ENV{BOOST_PATH})
endif()

#
# Setup our target
#

add_executable(${TARGET_NAME} main.cpp)


#
# Third-party includes/libraries
#

#target_include_directories(${TARGET_NAME} ${CONAN_INCLUDE_DIRS})
target_link_libraries(${TARGET_NAME} ${CONAN_LIBS})
