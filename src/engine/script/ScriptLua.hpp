/// @file

#pragma once

#include "script/IScript.hpp"

typedef struct lua_State lua_State;

class CScriptLua final : public IScript
{
public:
	CScriptLua();
	~CScriptLua();
	
	bool Init() override;
	void Shutdown() override;
	
	void Update(float afTimeStep) override;
	
	void CallFunc(const char *asName) override;
private:
	void PrintError();
	
	lua_State *mpState{nullptr};
};