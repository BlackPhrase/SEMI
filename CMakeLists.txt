cmake_minimum_required(VERSION 3.8)
project(V-Engine VERSION 0.1.4)

message(STATUS "${PROJECT_NAME} v.${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Declare available options
option(VENGINE_DEDICATED "Dedicated server build (skip client-side compilation)" OFF)
option(VENGINE_BUILD_EXAMPLES "Build examples" OFF)

# We want shared libraries (and modules) without any prefix in name
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")

# We want to use C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify output directory (for compiled binaries)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../redist)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../redist)

# Add include directories
include_directories(
	${CMAKE_SOURCE_DIR}/include/vengine
)

# Add subdirectories

## External dependencies
add_subdirectory(external)

## Main sources folder
add_subdirectory(src)

## Examples
if(VENGINE_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()