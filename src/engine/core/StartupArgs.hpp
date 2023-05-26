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

#pragma once

#include <CommonTypes.hpp>
#include <core/IStartupArgs.hpp>

class CStartupArgs final : public IStartupArgs
{
public:
	CStartupArgs(const char *asArgs);
	CStartupArgs(int anCount, char **asvValues);
	
	bool Contains(const char *asKey) const override; // TODO: return position?
	
	int GetCount() const override;
	
	const char *Get(const char *asKey) const override;
	
	const char *ToString() const override;
private:
	tStringMap mArgMap;
	tString msArgs{""};
};