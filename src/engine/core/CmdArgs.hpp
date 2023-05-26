/*
 * This file is part of V-Engine
 *
 * Copyright 2018-2019, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file
/// @brief command arguments

#pragma once

#include <CommonTypes.hpp>
#include <core/ICmdArgs.hpp>

class CCmdArgs final : public ICmdArgs
{
public:
	CCmdArgs(const char *asArgs);
	CCmdArgs(int anArgs, char **asvArg);
	~CCmdArgs();
	
	int GetCount() const override;
	
	const char *GetAt(int anIndex) const override;
	
	const char *ToString() const override;
private:
	tStringVec mvArgs;
	tString msArgs{""};
};