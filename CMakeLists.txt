cmake_minimum_required(VERSION 3.10)

if(DEFINED ENV{BUILD_VERSION})
  set(BUILD_VERSION $ENV{BUILD_VERSION})
else()
  set(BUILD_VERSION 1.0.0)
endif()

project(otus VERSION ${BUILD_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(googletest)

if(NOT DEFINED ENV{TRAVIS_BRANCH})
  set(NO_TRAVIS_BRANCH TRUE)
else()
  set(NO_TRAVIS_BRANCH FALSE)
endif()

if("$ENV{TRAVIS_BRANCH}" STREQUAL "master")
  set(IS_MASTER TRUE)
else()
  set(IS_MASTER FALSE)
endif()

if("$ENV{TRAVIS_BRANCH}" STREQUAL "homework1")
  set(IS_HW1 TRUE)
else()
  set(IS_HW1 FALSE)
endif()

if("$ENV{TRAVIS_BRANCH}" STREQUAL "homework2")
  set(IS_HW2 TRUE)
else()
  set(IS_HW2 FALSE)
endif()

if("$ENV{TRAVIS_BRANCH}" STREQUAL "homework4")
  set(IS_HW4 TRUE)
else()
  set(IS_HW4 FALSE)
endif()

if("$ENV{TRAVIS_BRANCH}" STREQUAL "homework5")
  set(IS_HW5 TRUE)
else()
  set(IS_HW5 FALSE)
endif()

if("$ENV{TRAVIS_BRANCH}" STREQUAL "homework7")
  set(IS_HW7 TRUE)
else()
  set(IS_HW7 FALSE)
endif()

if(${NO_TRAVIS_BRANCH} OR ${IS_MASTER} OR ${IS_HW1})
  add_subdirectory(homework1)
endif()

if(${NO_TRAVIS_BRANCH} OR ${IS_MASTER} OR ${IS_HW2})
  add_subdirectory(homework2)
endif()

if(${NO_TRAVIS_BRANCH} OR ${IS_MASTER} OR ${IS_HW4})
  add_subdirectory(homework4)
endif()

if(${NO_TRAVIS_BRANCH} OR ${IS_MASTER} OR ${IS_HW5})
  add_subdirectory(homework5)
endif()

if(${NO_TRAVIS_BRANCH} OR ${IS_MASTER} OR ${IS_HW7})
  add_subdirectory(homework7)
endif()
