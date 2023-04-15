/*
 * This file is part of V-Engine
 *
 * Copyright 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#ifdef _WIN32
#	include <windows.h>
#	include <tchar.h>
#endif

extern int VEngineMain(int argc, char **argv);

int main(int argc, char **argv)
{
	return VEngineMain(argc, argv);
};