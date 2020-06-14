cmake_minimum_required(VERSION 3.10)

project(tests_hw4)

add_executable(
  tests_hw4
  test_print_ip.cpp
)

target_include_directories(
  tests_hw4
  PRIVATE "${HOMEWORK4_DIR}/include"
          ${gtest_SOURCE_DIR}/include
          ${gtest_SOURCE_DIR}
)
target_link_libraries(
  tests_hw4
  PRIVATE gtest
          gtest_main
          pthread
)

add_test(test_howmework4 tests_hw4)
