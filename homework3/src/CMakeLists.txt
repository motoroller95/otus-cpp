cmake_minimum_required(VERSION 3.10)

project(allocator VERSION ${BUILD_VERSION})

add_executable(allocator "main.cpp")
target_include_directories(allocator PRIVATE ${HOMEWORK3_DIR}/include)

install(TARGETS hello_world_cli RUNTIME DESTINATION bin)
