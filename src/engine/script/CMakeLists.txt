project(vengine-script)

include_directories(
	${CMAKE_SOURCE_DIR}/external/lua53/include
)

link_directories(
	${CMAKE_SOURCE_DIR}/external/lua53/lib
)

file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(${PROJECT_NAME} MODULE ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_NAME "VEngineScript"
)

target_link_libraries(${PROJECT_NAME} -llua53)