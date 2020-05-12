cmake_minimum_required (VERSION 3.17)

project ("OpenGL")

if (CMAKE_COMPILER_IS_GNUCXX)
  add_definitions (-Wall -pedantic -std=gnu++2a)
endif ()

add_subdirectory ("Labs")
