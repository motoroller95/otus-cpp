cmake_minimum_required(VERSION 3.10)

project(ip_filter VERSION ${BUILD_VERSION})

add_subdirectory(ip_addr)

add_executable(ip_filter main.cpp)
add_library(
  ip_filter_library
  STATIC ip_filter.cpp
         filters.cpp
         reader.cpp
)

target_include_directories(ip_filter PRIVATE ${HOMEWORK2_DIR}/include)
target_include_directories(
  ip_filter_library
  PRIVATE ${HOMEWORK2_DIR}/include
          ${Boost_INCLUDE_DIRS}
)

target_link_libraries(ip_filter PRIVATE ip_filter_library)
target_link_libraries(
  ip_filter_library
  PRIVATE ip_addr
          ${Boost_LIBRARIES}
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)
