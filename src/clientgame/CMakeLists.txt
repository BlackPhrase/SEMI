project(vengine-clientgame)

include_directories(
	${CMAKE_SOURCE_DIR}/external/gwork/include
)

link_directories(
	${CMAKE_SOURCE_DIR}/external/gwork/lib
)

add_library(${PROJECT_NAME} MODULE)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SOURCES)

target_sources(${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_NAME "VEngineClientGame"
)

target_link_libraries(${PROJECT_NAME} GworkControls)