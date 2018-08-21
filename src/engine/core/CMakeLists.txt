project(VEngine-Core)

include_directories(
	${CMAKE_SOURCE_DIR}/external/shiftutil/include
	${CMAKE_SOURCE_DIR}/external/iniparser/src
)

file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(${PROJECT_NAME} MODULE ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_NAME "VEngineCore"
)

target_link_libraries(${PROJECT_NAME} iniparser)