/// @file

#include <lua.hpp>

#include "ScriptLua.hpp"

CScriptLua::CScriptLua() = default;
CScriptLua::~CScriptLua() = default;

bool CScriptLua::Init()
{
	mpState = luaL_newstate();
	
	// Make standard libraries available in the Lua state
	luaL_openlibs(mpState);
	
	auto nResult{luaL_loadfile(mpState, "test.lua")};
	
	if(nResult != LUA_OK)
	{
		PrintError();
		return false;
	};
	
	nResult = lua_pcall(mpState, 0, 0, 0);
	
	if(nResult != LUA_OK)
	{
		PrintError();
		return false;
	};

	return true;
};

void CScriptLua::Shutdown()
{
	lua_close(mpState);
};

void CScriptLua::Update(float afTimeStep)
{
};

void CScriptLua::CallFunc(const char *asName)
{
	lua_getglobal(mpState, asName);
	
	auto nResult{lua_pcall(mpState, 0, 0, 0)};
	
	if(nResult != LUA_OK)
	{
		PrintError();
		return;
	};
};

void CScriptLua::PrintError()
{
	auto sMsg{lua_tostring(mpState, -1)};
	printf("[LUA-ERROR] %s\n", sMsg);
	lua_pop(mpState, 1);
};