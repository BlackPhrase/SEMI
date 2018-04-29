if(NOT VENGINE_DEDICATED)
	add_subdirectory(client)
endif()

add_subdirectory(server)

add_subdirectory(network)
#add_subdirectory(physics) #TODO

add_subdirectory(core)