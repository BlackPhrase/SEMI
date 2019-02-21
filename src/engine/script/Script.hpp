/// @file

#pragma once

#include "script/IScript.hpp"

class CScript final : public IScript
{
public:
	CScript(const ICoreEnv &apCoreEnv);
	~CScript();
	
	bool Init() override;
	void Shutdown() override;
	
	IScriptVM *CreateVM() override;
	void DestroyVM(IScriptVM *apVM) override;
private:
	const ICoreEnv &mpCoreEnv;
};