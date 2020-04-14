cmake_minimum_required(VERSION 3.10)

project(test_ip_addr)

add_library(
  tests_ip_addr
  STATIC test_builder.cpp
         test_ip_addr.cpp
         test_validator.cpp
)

target_include_directories(
  tests_ip_addr
  PRIVATE "${HOMEWORK2_DIR}/include"
          ${gtest_SOURCE_DIR}/include
          ${gtest_SOURCE_DIR}
          ${Boost_INCLUDE_DIRS}
)
target_link_libraries(
  tests_ip_addr
  PRIVATE gtest
          gtest_main
          pthread
          ip_filter_library
          ${Boost_LIBRARIES}
)
