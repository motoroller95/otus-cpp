cmake_minimum_required(VERSION 3.10)

project(homework6 VERSION ${BUILD_VERSION})

SET(HOMEWORK6_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(tests)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION ${BUILD_VERSION})
set(CPACK_PACKAGE_NAME matrix)
set(CPACK_PACKAGE_FILE_NAME ${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION})
set(CPACK_PACKAGE_CONTACT motoroller95@gmail.com)

configure_file(bintray-descriptor.json ${CMAKE_BINARY_DIR}/homework4/bintray-descriptor.json)

include(CPack)
