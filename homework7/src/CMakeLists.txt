cmake_minimum_required(VERSION 3.10)

project(cmd VERSION ${BUILD_VERSION})

add_executable(cmd "main.cpp" "bulk_cmd_processor.cpp")

target_include_directories(cmd PRIVATE ${HOMEWORK7_DIR}/include)

install(TARGETS cmd RUNTIME DESTINATION bin)
