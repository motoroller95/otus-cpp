cmake_minimum_required(VERSION 3.10)

project(print_ip VERSION ${BUILD_VERSION})

add_executable(print_ip "main.cpp" )

target_include_directories(print_ip PRIVATE ${HOMEWORK4_DIR}/include)

install(TARGETS print_ip RUNTIME DESTINATION bin)
