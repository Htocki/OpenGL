cmake_minimum_required (VERSION 3.17)

project ("OpenGL")

if (CMAKE_COMPILER_IS_GNUCXX)
  add_definitions (-Wall -pedantic -std=gnu++2a)
endif ()

add_subdirectory ("L1/Part1/Example2")
add_subdirectory ("L1/Part1/OpenGLSource")
# add_subdirectory ("L1/Part2/Example1")