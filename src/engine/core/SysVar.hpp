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

#include <CommonTypes.hpp>
#include <core/ISysVar.hpp>

// TODO: CConVar?
class CSysVar final : public ISysVar
{
public:
	CSysVar(const tString &asName, const tString &asValue, const tString &asDesc = "<no desc>")
		: msName(asName), msDesc(asDesc), msValue(asValue), msDefValue(asValue){}
	~CSysVar() = default;
	
	const char *GetName() const override {return msName.c_str();}
	const char *GetDescription() const override {return msDesc.c_str();}
	
	void SetValue(const char *asValue) override
	{
		msValue = asValue;
		// TODO: notify the change value listener(s)
	};
	
	const char *GetValue() const override {return msValue.c_str();}
	const char *GetDefValue() const override {return msDefValue.c_str();}
	
	// TODO: GetInt(), GetFloat(), GetBool()
	
	void ResetValue(){SetValue(msDefValue);}
private:
	tString msName{""};
	tString msDesc{""};
	tString msValue{""};
	tString msDefValue{""};
};