project(vengine-launcher)

include_directories(
	${CMAKE_SOURCE_DIR}/external/konbinilib/include
)

if(WIN32)
	add_executable(${PROJECT_NAME} ${PROJECT_SOURCES}) # TODO: WIN32
else()
	add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
endif()

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SOURCES)

target_sources(${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCES}
)

if(WIN32)
	add_subdirectory(win)
else()
	add_subdirectory(unix)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_NAME "VEngineLauncher"
)