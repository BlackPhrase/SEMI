project(vengine-client)

add_definitions(-DGLFW_DLL)

include_directories(
	${CMAKE_SOURCE_DIR}/external/konbinilib/include
	${CMAKE_SOURCE_DIR}/external/glfw3/include
)

link_directories(
	${CMAKE_SOURCE_DIR}/external/glfw3/lib
)

add_library(${PROJECT_NAME} MODULE)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SOURCES)

target_sources(${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_NAME "VEngineClient"
)

target_link_libraries(${PROJECT_NAME} -lglfw3dll)

if(WIN32)
	target_link_libraries(${PROJECT_NAME} -lopengl32)
else()
	target_link_libraries(${PROJECT_NAME} -lGL)
endif()