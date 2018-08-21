project(VEngine-Client)

add_definitions(-DGLFW_DLL)

include_directories(
	${CMAKE_SOURCE_DIR}/external/glfw3/include
	${CMAKE_SOURCE_DIR}/external/shiftutil/include
)

link_directories(
	${CMAKE_SOURCE_DIR}/external/glfw3/lib
)

file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(${PROJECT_NAME} MODULE ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_NAME "VEngineClient"
)

target_link_libraries(${PROJECT_NAME} -lglfw3dll)

if(WIN32)
	target_link_libraries(${PROJECT_NAME} -lopengl32)
else()
	target_link_libraries(${PROJECT_NAME} -lGL)
endif()