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
#include "ISysCmd.hpp"

class CBaseSysCmd : public ISysCmd
{
public:
	CBaseSysCmd(tStringView asName, tStringView asDesc = "<no desc>")
		: msName(asName), msDesc(asDesc){}
	
	const char *GetName() const override final {return msName.c_str();}
	const char *GetDesc() const override final {return msDesc.c_str();}
private:
	tString msName{""};
	tString msDesc{""};
};