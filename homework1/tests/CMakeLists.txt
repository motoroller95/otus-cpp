cmake_minimum_required(VERSION 3.2)

project(tests VERSION 0.0.1)

find_package(GTest REQUIRED)

file(GLOB_RECURSE TESTS_SRC "*.cpp")
add_executable(tests ${TESTS_SRC})

set_target_properties(tests PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
)

target_include_directories(tests PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(tests PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread helloworld)

if (MSVC)
  target_compile_options(tests PRIVATE /W4)
else ()
  target_compile_options(tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

add_test(tests tests)
