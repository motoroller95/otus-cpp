cmake_minimum_required(VERSION 3.10)

project(homework1 VERSION ${BUILD_VERSION})

SET(HOMEWORK1_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(PROCESSED_HEADERS_DIR ${CMAKE_CURRENT_BINARY_DIR}/include)

configure_file(include/version.h.in ${PROCESSED_HEADERS_DIR}/version.h)

add_subdirectory(src)
add_subdirectory(tests)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION ${BUILD_VERSION})
set(CPACK_PACKAGE_NAME hello_world_cli)
set(CPACK_PACKAGE_FILE_NAME ${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION})
set(CPACK_PACKAGE_CONTACT motoroller95@gmail.com)

configure_file(bintray-descriptor.json ${CMAKE_BINARY_DIR}/homework1/bintray-descriptor.json)

include(CPack)
