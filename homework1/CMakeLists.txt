cmake_minimum_required(VERSION 3.2)

project(homework1 VERSION 0.0.1)

configure_file(include/version.h.in include/version.h)

add_subdirectory(lib/hello_world)
add_subdirectory(tests)

file(GLOB_RECURSE HELLOWORLD_CLI_SRC "src/*.cpp")
add_executable(helloworld_cli ${HELLOWORLD_CLI_SRC})

set_target_properties(helloworld_cli tests PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
)

target_include_directories(helloworld_cli PRIVATE "include" "${CMAKE_BINARY_DIR}/include")
target_link_libraries(helloworld_cli PRIVATE helloworld)

if (MSVC)
  target_compile_options(helloworld_cli PRIVATE /W4)
else ()
  target_compile_options(helloworld_cli PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT motoroller95@gmail.com)

include(CPack)

enable_testing()

