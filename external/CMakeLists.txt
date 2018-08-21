include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/konbinilib/include
	${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src
)

#add_subdirectory(
	#${CMAKE_CURRENT_SOURCE_DIR}/konbinilib/include
#)

add_library(iniparser STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src/dictionary.c
	${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src/iniparser.c
)