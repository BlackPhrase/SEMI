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

#pragma once

#include <vector>

//#include <core/ISysVarRegistry.hpp>

class ISysVar;
using tSysVarVec = std::vector<ISysVar*>;

class CSysVarRegistry final //: public ISysVarRegistry
{
public:
	CSysVarRegistry();
	~CSysVarRegistry();
	
	ISysVar *Add(const char *asName, const char *asDefValue, const char *asDescription); //override;
	bool Register(ISysVar *apVar); //override;
	bool Remove(const char *asName); //override;
	
	ISysVar *Find(const char *asName) const; //override;
private:
	tSysVarVec mvVars;
};