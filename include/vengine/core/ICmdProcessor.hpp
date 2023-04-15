/*
 * This file is part of V-Engine
 *
 * Copyright 2018, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file
/// @brief command processor interface

#pragma once

struct ICmdProcessor
{
	///
	virtual void InsertText(const char *asText) = 0;
	
	///
	virtual void AppendText(const char *asText) = 0;
	
	///
	virtual void ExecText(const char *asText) = 0;
	
	///
	virtual void ExecPending() = 0;
};