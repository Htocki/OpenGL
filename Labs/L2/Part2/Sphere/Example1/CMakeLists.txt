cmake_minimum_required (VERSION 3.17)

project ("Sphere-Example1")

add_executable (${PROJECT_NAME} "src/Main.cpp")

set_target_properties (
  ${PROJECT_NAME}
    PROPERTIES
      set (CMAKE_CXX_STANDARD 20)
      set (CMAKE_CXX_STANDARD_REQUIRED ON)
)

find_package (OpenGL REQUIRED)
find_package (GLUT REQUIRED)

target_link_libraries (
  ${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARY}
)