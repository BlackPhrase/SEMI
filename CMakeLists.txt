cmake_minimum_required(VERSION 3.8)
project(V-Engine VERSION 0.1.9)

message(STATUS "${PROJECT_NAME} v.${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Declare available options
option(VENGINE_DEDICATED "Dedicated server build (skip client-side compilation)" OFF)
option(VENGINE_BUILD_EXAMPLES "Build examples" OFF)
option(VENGINE_SINGLEGAMEDLL "Use single game dll for both client and server sides" OFF)
option(VENGINE_DEV "I'm a developer and I need some additional features" OFF)

if(VENGINE_DEV)
	add_definitions(-DVENGINE_DEV)
endif()

# We want shared libraries (and modules) without any prefix in name
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")

# We want to use C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify output directory (for compiled binaries)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../redist)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../redist)

set(VENGINE_PRESET_TYPE_DEFAULT 308)

if(NOT VENGINE_PRESET_TYPE)
    set(VENGINE_PRESET_TYPE Default CACHE STRING
        "Choose the type of engine features preset"
        FORCE
	)
    set_property(CACHE VENGINE_PRESET_TYPE PROPERTY STRINGS
		Default
		Custom
		308
		324
	)
endif()

if(VENGINE_PRESET_TYPE STREQUAL Default)
	set(VENGINE_PRESET_TYPE ${VENGINE_PRESET_TYPE_DEFAULT})
endif()

if(VENGINE_PRESET_TYPE EQUAL 308)
	set(VENGINE_SINGLEGAMEDLL ON CACHE BOOL "Use single game dll for both client and server sides" FORCE)
elseif(VENGINE_PRESET_TYPE EQUAL 324)
	set(VENGINE_SINGLEGAMEDLL OFF CACHE BOOL "Use single game dll for both client and server sides" FORCE)
endif()

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