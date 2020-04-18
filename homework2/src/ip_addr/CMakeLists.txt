cmake_minimum_required(VERSION 3.10)

project(ip_addr VERSION ${BUILD_VERSION})

add_library(ip_addr STATIC builder.cpp ip_addr.cpp validator.cpp)

target_include_directories(
  ip_addr
  PRIVATE ${HOMEWORK2_DIR}/include
          ${Boost_INCLUDE_DIRS}
)

target_link_libraries(ip_addr PRIVATE ${Boost_LIBRARIES})
