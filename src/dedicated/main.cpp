#include <cstdlib>
#include "konbini/shared_lib.hpp"
#include "vengine/IEngineCore.hpp"

int main(int argc, char **argv)
{
	konbini::shared_lib EngineCoreLib("VEngineCore");
	
	if(!EngineCoreLib)
		return EXIT_FAILURE;
	
	auto fnGetEngineCore{EngineCoreLib.getexportfunc<pfnGetEngineCore>("GetEngineCore")};
	
	if(!fnGetEngineCore)
		return EXIT_FAILURE;
	
	auto pEngine{fnGetEngineCore(IEngineCore::Version)};
	
	if(!pEngine)
		return EXIT_FAILURE;
	
	IEngineCore::InitParams VEngineInitParams{};
	
	VEngineInitParams.ExecMode = IEngineCore::Mode::DedicatedServer;
	
	pEngine->Init(VEngineInitParams);
	
	while(pEngine->Frame()) // TODO: geez...
		;
	
	pEngine->Shutdown();
	
	return EXIT_SUCCESS;
};