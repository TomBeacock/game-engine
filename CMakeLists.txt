# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.12)

project ("game-engine")

# Include sub-projects.
add_subdirectory ("extern")
add_subdirectory ("engine")
add_subdirectory ("test-client")
