/// @file

#pragma once

#include "CommonTypes.hpp"
#include "core/ICvar.hpp"

class CCvar final : public ICvar
{
public:
	CCvar(const tString &asName, const tString &asValue, const tString &asDesc = "")
		: msName(asName), msDesc(asDesc), msValue(asValue), msDefValue(asValue){}
	~CCvar() = default;
	
	const char *GetName() const override {return msName.c_str();}
	const char *GetDescription() const override {return msDesc.c_str();}
	
	void SetValue(const char *asValue) override {msValue = asValue;}
	
	const char *GetValue() const override {return msValue.c_str();}
	const char *GetDefValue() const override {return msDefValue.c_str();}
	
	void ResetValue(){msValue = msDefValue;}
private:
	tString msName{""};
	tString msDesc{""};
	tString msValue{""};
	tString msDefValue{""};
};