cmake_minimum_required (VERSION 3.17)

project ("OpenGL")

if (CMAKE_COMPILER_IS_GNUCXX)
  add_definitions (-Wall -pedantic -std=gnu++2a)
endif ()

add_subdirectory ("L2/Part1/Lines")
add_subdirectory ("L2/Part1/Linestrip")
add_subdirectory ("L2/Part1/Triangles")
add_subdirectory ("L2/Part1/Whiteline")
add_subdirectory ("L2/Part1/Grid")