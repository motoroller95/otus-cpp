cmake_minimum_required(VERSION 3.10)

project(tests_hw2)

add_executable(tests_hw2 "main_test.cpp")

add_subdirectory(ip_addr)

target_include_directories(
  tests_hw2
  PRIVATE "${HOMEWORK2_DIR}/include"
          ${gtest_SOURCE_DIR}/include
          ${gtest_SOURCE_DIR}
          ${Boost_INCLUDE_DIRS}
)
target_link_libraries(
  tests_hw2
  PRIVATE tests_ip_addr
          gtest
          gtest_main
          pthread
          ip_filter_library
          ${Boost_LIBRARIES}
)

add_test(test_howmework2 tests_hw2)
