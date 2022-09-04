cmake_minimum_required (VERSION 3.12)

project("engine")

add_library (engine
"include/core.h"
"system/window.h"
"system/application.h"
"system/application.cpp"
"platform/windows/windows.cpp"
"platform/windows/windows-window.h"
"platform/windows/windows-window.cpp"
)

set_target_properties(engine PROPERTIES CXX_STANDARD 20)

find_package (OpenGL REQUIRED)

target_link_libraries (engine opengl32)

target_include_directories (engine PUBLIC
"${PROJECT_SOURCE_DIR}"
"${CMAKE_SOURCE_DIR}/engine"
"${CMAKE_SOURCE_DIR}/extern/glad/include"
)
