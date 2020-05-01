cmake_minimum_required (VERSION 3.17)

project ("OpenGL")

if (CMAKE_COMPILER_IS_GNUCXX)
  add_definitions (-Wall -pedantic -std=gnu++2a)
endif ()

add_subdirectory ("L1/Part1/Example2")
add_subdirectory ("L1/Part1/OpenGLSource")

add_subdirectory ("L2/Part1/Ellipse")
add_subdirectory ("L2/Part1/Grid")
add_subdirectory ("L2/Part1/Hyperbola")
add_subdirectory ("L2/Part1/Lines")
add_subdirectory ("L2/Part1/Linestrip")
add_subdirectory ("L2/Part1/Ortho")
add_subdirectory ("L2/Part1/Triangles")
add_subdirectory ("L2/Part1/Whiteline")

add_subdirectory ("L2/Part2/Teapot")
add_subdirectory ("L2/Part2/Sphere")

add_subdirectory ("L3/Part1")