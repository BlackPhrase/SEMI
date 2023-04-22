/*
 * This file is part of V-Engine
 *
 * Copyright 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include <cstdio>
#include <cstring>

#include <string_view>

#include <CommonTypes.hpp>
#include <BaseEngineModule.hpp>

void ActuallyDoABarrelRoll()
{
	printf("Barrel roll!\n");
};

struct ISomeInterface
{
	//int mnVersion{1};
	static constexpr auto mnVersion{1};
	
	///
	//void (*DoABarrelRoll)();
	virtual void DoABarrelRoll() = 0;
};

class CSomeInterfaceImpl : public ISomeInterface
{
public:
	void DoABarrelRoll() override
	{
		ActuallyDoABarrelRoll();
	};
};

class CTestEngineModule : public CBaseEngineModule
{
public:
	CTestEngineModule(const ICoreEnv &aCoreEnv)
	{
		// TODO: try to init something
	};
	
	~CTestEngineModule()
	{
		if(mpSomeInterface)
		{
			delete mpSomeInterface;
			mpSomeInterface = nullptr;
		};
		
		// TODO: call some shutdown procedures here
	};
	
	bool OnLoad() override
	{
		// TODO: try to init something
		
		mpSomeInterface = new CSomeInterfaceImpl;
		//mpSomeInterface.DoABarrelRoll = ActuallyDoABarrelRoll;
		
		RegisterInterface("SomeInterface", [=, this](int anVersion) -> void* {
			//if(mpSomeInterface->mnVersion == anVersion)
			if(ISomeInterface::mnVersion == anVersion)
				return mpSomeInterface;
			
			return nullptr;
		});
		
		return true;
	};
	
	bool OnUnload() override
	{
		// TODO: call some shutdown procedures here
		
		return true;
	};
private:
	ISomeInterface *mpSomeInterface{nullptr};
};

//

CTestEngineModule *gpTestEngineModule{nullptr};

// TODO: SEMIModuleInit? VEngineModuleLoad?
C_EXPORT int VEngineModuleInit(const ICoreEnv &aCoreEnv)
{
	gpTestEngineModule = new CTestEngineModule(aCoreEnv);
	
	return 1;
};

// TODO: SEMIModuleShutdown? VEngineModuleUnload?
C_EXPORT void VEngineModuleShutdown(const ICoreEnv &aCoreEnv)
{
	if(gpTestEngineModule)
	{
		delete gpTestEngineModule;
		gpTestEngineModule = nullptr;
	};
};

//

// TODO: SEMIModuleMain?
C_EXPORT IEngineModule *VEngineModuleMain(const ICoreEnv &aCoreEnv)
{
	static CTestEngineModule TestEngineModule(aCoreEnv);
	
	//if(!TestEngineModule.Init(aCoreEnv))
		//return nullptr;
	
	return &TestEngineModule;
};