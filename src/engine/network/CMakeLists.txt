project(VEngine-Network)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
if(WIN32)
	${CMAKE_CURRENT_SOURCE_DIR}/win/*.cpp
else()
	# TODO
endif()
)

add_library(${PROJECT_NAME} MODULE ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_NAME "VEngineNetwork"
)

if(WIN32)
target_link_libraries(${PROJECT_NAME} ws2_32)
endif()