cmake_minimum_required(VERSION 3.10)

project(tests)

file(GLOB_RECURSE TESTS_SRC "*.cpp")
add_executable(tests ${TESTS_SRC})

target_include_directories(tests PRIVATE "${HOMEWORK1_DIR}/include" ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(tests PRIVATE gtest gtest_main pthread hello_world)

if (MSVC)
  target_compile_options(tests PRIVATE /W4)
else ()
  target_compile_options(tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

add_test(test_helloworld tests)
