cmake_minimum_required(VERSION 3.8)
project(V-Engine)

include_directories(
	${CMAKE_SOURCE_DIR}/include
)

add_subdirectory(external)

add_subdirectory(src)