/// @file

#include <vengine/IEngineModule.hpp>

#include <cstdio>
#include <cstring>

#include <string_view>

void ActuallyDoABarrelRoll()
{
	printf("Barrel roll!\n");
};

struct SSomeInterface
{
	int mnVersion{1};
	
	///
	void (*DoABarrelRoll)();
};

class CBaseEngineModule
{
public:
	CBaseEngineModule(const ICoreEnv &aCoreEnv)
	{
		// TODO: try to init something
		
		mpSomeInterface = new SSomeInterface;
		mpSomeInterface.DoABarrelRoll = ActuallyDoABarrelRoll;
	};
	
	~CBaseEngineModule()
	{
		delete mpSomeInterface;
		
		// TODO: call some shutdown procedures here
	};
	
	void *GetInterface(std::string_view asName, int anVersion)
	{
		using namespace std::literals;
		
		if(asName == "SomeInterface"sv)
			if(mpSomeInterface->mnVersion == anVersion)
				return mpSomeInterface;
		
		return nullptr;
	};
private:
	SSomeInterface *mpSomeInterface{nullptr};
};

CBaseEngineModule *gpTestEngineModule{nullptr};

void *TestEngineModule_GetInterface(const char *asName, int anVersion)
{
	std::string_view sInterfaceName{asName};
	return gpTestEngineModule->GetInterface(sInterfaceName, anVersion);
};

IEngineModule TestEngineModule = {
	TestEngineModule_GetInterface
};

//

C_EXPORT int SEMIModuleInit(const ICoreEnv &aCoreEnv)
{
	gpTestEngineModule = new CBaseEngineModule(aCoreEnv);
	
	return 1;
};

C_EXPORT void SEMIModuleShutdown(const ICoreEnv &aCoreEnv)
{
	if(gpTestEngineModule)
	{
		delete gpTestEngineModule;
		gpTestEngineModule = nullptr;
	};
};

//

C_EXPORT IEngineModule *SEMIModuleMain(const ICoreEnv &aCoreEnv)
{
	//if(!TestEngineModule.Init(aCoreEnv))
		//return nullptr;
	
	return &TestEngineModule;
};