cmake_minimum_required(VERSION 3.8)
project(V-Engine)

# Declare available options
option(VENGINE_DEDICATED "Dedicated server build (skip client-side compilation)" OFF)

# We want shared libraries (and modules) without any prefix in name
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")

# Add include directories
include_directories(
	${CMAKE_SOURCE_DIR}/include
)

# Add subdirectories
add_subdirectory(external)

add_subdirectory(src)