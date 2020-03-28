cmake_minimum_required(VERSION 3.10)

project(helloworld VERSION 1.0.0)

file(GLOB_RECURSE _SRCS "src/*.cpp")
file(GLOB_RECURSE _HRS "include/*.cpp")
add_library(helloworld STATIC ${_SRCS} ${_HRS})

target_include_directories(helloworld PUBLIC include)

set_target_properties(helloworld PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED YES
)
