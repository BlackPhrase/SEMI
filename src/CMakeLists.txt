add_subdirectory(engine)

if(NOT VENGINE_DEDICATED)
	add_subdirectory(clientgame)
endif()

add_subdirectory(game)

#if(VENGINE_DEDICATED)
	add_subdirectory(dedicated)
#else()
	add_subdirectory(launcher)
#endif()

add_subdirectory(editor)