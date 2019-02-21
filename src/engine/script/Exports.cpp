/// @file

#include "CommonTypes.hpp"
#include "Script.hpp"

C_EXPORT IScript *GetScript(int anVersion)
{
	if(anVersion == IScript::Version)
	{
		static CScript Script(apCoreEnv);
		return &Script;
	};
	
	return nullptr;
};