cmake_minimum_required(VERSION 3.2)

project(hello_world_cli VERSION 0.0.1$ENV{TRAVIS_BUILD_NUMBER})

file(GLOB_RECURSE HELLOWORLD_CLI_SRC )
add_executable(hello_world_cli "main.cpp" "version.cpp")
add_library(hello_world STATIC "hello_world.cpp")

target_include_directories(hello_world_cli PRIVATE ${HOMEWORK1_DIR}/include ${PROCESSED_HEADERS_DIR})
target_include_directories(hello_world PRIVATE ${HOMEWORK1_DIR}/include)

target_link_libraries(hello_world_cli hello_world)
