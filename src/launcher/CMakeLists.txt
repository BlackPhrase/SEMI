project(VEngine-Launcher)

include_directories(
	${CMAKE_SOURCE_DIR}/external/shiftutil/include
)

file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

if(WIN32)
	add_executable(${PROJECT_NAME} ${PROJECT_SOURCES}) # TODO: WIN32
else()
	add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_NAME "VEngineLauncher"
)