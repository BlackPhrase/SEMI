if(NOT VENGINE_DEDICATED)
	#add_subdirectory(input)
	#add_subdirectory(sound)
	#add_subdirectory(render)
	add_subdirectory(client)
endif()

add_subdirectory(server)

add_subdirectory(network)
#add_subdirectory(physics) # TODO
add_subdirectory(script)

add_subdirectory(core)