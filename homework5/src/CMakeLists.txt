cmake_minimum_required(VERSION 3.10)

project(editor VERSION ${BUILD_VERSION})

add_executable(editor "main.cpp" "common.cpp" )

target_include_directories(editor PRIVATE ${HOMEWORK5_DIR}/include)

install(TARGETS editor RUNTIME DESTINATION bin)
