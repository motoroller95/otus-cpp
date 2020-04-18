cmake_minimum_required(VERSION 3.10)

project(homework2 VERSION ${BUILD_VERSION})

SET(HOMEWORK2_DIR ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost REQUIRED)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
endif()

add_subdirectory(src)
add_subdirectory(tests)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION ${BUILD_VERSION})
set(CPACK_PACKAGE_NAME ip_filter)
set(CPACK_PACKAGE_FILE_NAME ${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION})
set(CPACK_PACKAGE_CONTACT motoroller95@gmail.com)

configure_file(bintray-descriptor.json ${CMAKE_BINARY_DIR}/homework2/bintray-descriptor.json)

include(CPack)
