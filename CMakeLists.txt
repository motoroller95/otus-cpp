cmake_minimum_required(VERSION 3.10)

if(DEFINED $ENV{BUILD_VERSION})
  set(BUILD_VERSION ENV{BUILD_VERSION})
else()
  set(BUILD_VERSION 1.0.0)
endif()

project(otus VERSION ${BUILD_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(homework1)
