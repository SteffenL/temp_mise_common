cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

project(mise_common)
set(TARGET_NAME mise_common)


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


include_directories(
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/thirdparty/nowide"
)

file(GLOB_RECURSE Sources
    "src/*.cpp"
    "thirdparty/nowide/src/*.cpp"
)

add_library(${TARGET_NAME} STATIC ${Sources})

#target_include_directories(${TARGET_NAME}
#    PUBLIC include
#    PUBLIC thirdparty/nowide
#)


#
# Third-party includes/libraries
#

if(USE_CONAN)
    #target_include_directories(${TARGET_NAME}
    #    ${CONAN_INCLUDE_DIRS_BOOST}
    #)
else()
    target_include_directories(${TARGET_NAME} PUBLIC ${BOOST_PATH})
    target_link_libraries(${TARGET_NAME} "${BOOST_PATH}/stage/lib")
endif()
