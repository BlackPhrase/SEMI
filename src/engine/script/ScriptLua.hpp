/// @file

#pragma once

#include "script/IScript.hpp"

typedef struct lua_State lua_State;

class CScriptLua final : public IScriptVM
{
public:
	CScriptLua();
	~CScriptLua();
	
	void CallFunc(const char *asName) override;
private:
	void PrintError();
	
	lua_State *mpState{nullptr};
};