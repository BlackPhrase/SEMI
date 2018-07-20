/// @file

#include "CommonTypes.hpp"
#include "BlankEngineModule.hpp"

C_EXPORT void ModuleMain(SEngineModuleInfo &apInfo, IModuleManager *apModuleManager)
{
	apInfo.msName = "Engine Module Sample";
	apInfo.msVersion = "0.1 Alpha";
	apInfo.msAuthor = "V-Engine Dev Team";
	
	static CEngineModule Module;
	apModuleManager->RegisterModule(&Module);
};