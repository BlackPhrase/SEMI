#include <cstdlib>
#include "shiftutil/shared_lib.hpp"
#include "vengine/IEngineCore.hpp"

int main(int argc, char **argv)
{
	shiftutil::shared_lib EngineCoreLib("VEngineCore");
	
	//if(!EngineCoreLib) // TODO: add operator bool overload to shared_lib
		//return EXIT_FAILURE;
	
	auto fnGetEngineCore{EngineCoreLib.getexportfunc<pfnGetEngineCore>("GetEngineCore")};
	
	if(!fnGetEngineCore)
		return EXIT_FAILURE;
	
	auto pEngine{fnGetEngineCore(IEngineCore::Version)};
	
	if(!pEngine)
		return EXIT_FAILURE;
	
	IEngineCore::InitParams VEngineInitParams{};
	
	pEngine->Init(VEngineInitParams);
	
	while(pEngine->Frame()) // TODO: geez...
		;
	
	pEngine->Shutdown();
	
	return EXIT_SUCCESS;
};