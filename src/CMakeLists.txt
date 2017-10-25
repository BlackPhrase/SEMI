if(NOT VENGINE_DEDICATED)
	add_subdirectory(client)
endif()

add_subdirectory(server)
add_subdirectory(core)
add_subdirectory(launcher)