cmake_minimum_required(VERSION 3.10)

project(tests_hw2)

add_executable(
  tests_hw2
  test_reader.cpp
  test_filters.cpp
  test_ip_filter.cpp
  ip_addr/test_validator.cpp
  ip_addr/test_ip_addr.cpp
  ip_addr/test_builder.cpp
)

target_include_directories(
  tests_hw2
  PRIVATE "${HOMEWORK2_DIR}/include"
          ${gtest_SOURCE_DIR}/include
          ${gtest_SOURCE_DIR}
          ${Boost_INCLUDE_DIRS}
)
target_link_libraries(
  tests_hw2
  PRIVATE ip_filter_library
          gtest
          gtest_main
          pthread
          ${Boost_LIBRARIES}
)

add_test(test_howmework2 tests_hw2)
