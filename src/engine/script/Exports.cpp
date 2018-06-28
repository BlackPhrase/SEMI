/// @file

#include "CommonTypes.hpp"
#include "ScriptLua.hpp"

C_EXPORT IScript *GetScript(int anVersion)
{
	if(anVersion == IScript::Version)
	{
		static CScriptLua Script;
		return &Script;
	};
};