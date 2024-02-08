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
#include "ISystem.hpp"

class CBaseSysCmd : public ISysCmd
{
public:
	CBaseSysCmd(tStringView asName, tStringView asDesc = "<no desc>")
		: CBaseSysCmd(nullptr, asName, asDesc){}
	CBaseSysCmd(ISystem *apSystem, tStringView asName, tStringView asDesc = "<no desc>")
		: mpSystem(apSystem), msName(asName), msDesc(asDesc)
	{
		if(mpSystem)
			mpSystem->RegisterCmd(this);
	};
	
	virtual ~CBaseSysCmd()
	{
		if(mpSystem)
			mpSystem->RemoveCmd(GetName());
	};
	
	const char *GetName() const override final {return msName.c_str();}
	const char *GetDesc() const override final {return msDesc.c_str();}
private:
	tString msName{""};
	tString msDesc{""};
	
	ISystem *mpSystem{nullptr};
};