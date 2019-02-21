/// @file
/// @brief scripting module interface

#pragma once

struct ICoreEnv;

struct IScriptVM
{
	///
	virtual void CallFunc(const char *asName) = 0;
};

struct IScript
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	virtual bool Init() = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual IScriptVM *CreateVM() = 0;
	
	///
	virtual void DestroyVM(IScriptVM *apVM) = 0;
};

using pfnGetScript = IScript *(*)(int anVersion, const ICoreEnv &apCoreEnv);