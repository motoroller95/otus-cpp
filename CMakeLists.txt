cmake_minimum_required(VERSION 3.2)

project(otus VERSION 0.0.1$ENV{TRAVIS_BUILD_NUMBER})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(homework1)
