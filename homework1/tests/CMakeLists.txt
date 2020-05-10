cmake_minimum_required(VERSION 3.10)

project(tests_hw1)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
endif()

add_executable(tests_hw1 "test_hello_world.cpp")

target_include_directories(tests_hw1 PRIVATE "${HOMEWORK1_DIR}/include" ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(tests_hw1 PRIVATE gtest gtest_main pthread hello_world)

add_test(test_helloworld tests_hw1)
