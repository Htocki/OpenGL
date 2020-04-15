cmake_minimum_required (VERSION 3.17)

project ("Example1")

set (HEADERS "include/Widget.h")
set (SOURCES "src/Widget.cpp" "src/Main.cpp")

add_executable (${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_target_properties (
  ${PROJECT_NAME}
    PROPERTIES
      set (CMAKE_CXX_STANDARD 20)
      set (CMAKE_CXX_STANDARD_REQUIRED ON)
)

find_package (OpenGL REQUIRED)
find_package (GLUT REQUIRED)
find_package (Qt5
  COMPONENTS
    Core
    Widgets
  REQUIRED
)

message ("!!! Qt5Core_FOUND: ${Qt5Core_FOUND}")
message ("!!! Qt5Widgets_FOUND: ${Qt5Widgets_FOUND}\n")
message ("!!! Qt5Core_INCLUDE_DIRS: ${Qt5Core_INCLUDE_DIRS}")
message ("!!! Qt5Widgets_INCLUDE_DIRS: ${Qt5Widgets_INCLUDE_DIRS}\n")

set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTORCC ON)
set (CMAKE_AUTOUIC ON)

target_link_libraries (
  ${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARY}
    ${Qt5Core_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
)

include_directories (${Qt5Widgets_INCLUDE_DIRS})
include_directories (${Qt5Core_INCLUDE_DIRS})

target_include_directories (
  ${PROJECT_NAME}
    PUBLIC 
      $<INSTALL_INTERFACE:include>    
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/src
)


