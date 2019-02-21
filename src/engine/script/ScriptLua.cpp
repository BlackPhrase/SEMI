/// @file

#include <lua.hpp>

#include "ScriptLua.hpp"

extern "C" int test(lua_State *apState)
{
	// The number of function arguments will be on top of the stack
	auto nArgs{lua_gettop(apState)};
	
	//lua_tostring(apState, nArgs);
	
	//lua_pushnumber(apState, 123);
	
	// Let Lua know how many return values we've passed
	return 0;
};

CScriptLua::CScriptLua()
{
	mpState = luaL_newstate();
	
	lua_register(mpState, "test", test);
	
	// Make standard libraries available in the Lua state
	luaL_openlibs(mpState);
	
	auto nResult{luaL_loadfile(mpState, "test.lua")};
	
	if(nResult != LUA_OK)
	{
		PrintError();
	};
	
	nResult = lua_pcall(mpState, 0, 0, 0);
	
	if(nResult != LUA_OK)
	{
		PrintError();
	};
};

CScriptLua::~CScriptLua()
{
	lua_close(mpState);
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