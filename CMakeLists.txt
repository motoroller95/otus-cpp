cmake_minimum_required(VERSION 3.10)

if(NOT DEFINED ENV{BUILD_VERSION})
    message(FATAL_ERROR "BUILD_VERSION environment variable undefined. run BUILD_VERSION=1.0.0 cmake CMakeLists.txt")
endif()

project(otus VERSION $ENV{BUILD_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(homework1)
