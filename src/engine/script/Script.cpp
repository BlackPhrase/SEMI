/// @file

#include "Script.hpp"
#include "ScriptLua.hpp"

CScript::CScript(const ICoreEnv &apCoreEnv) : mpCoreEnv(apCoreEnv){}

CScript::~CScript() = default;

bool CScript::Init()
{
	return true;
};

void CScript::Shutdown()
{
};

IScriptVM *CScript::CreateVM()
{
	return new CScriptLua();
};

void CScript::DestroyVM(IScriptVM *apVM)
{
	if(apVM)
	{
		delete apVM;
		apVM = nullptr;
	};
};