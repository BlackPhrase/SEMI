#include <cstdlib>
#include "shiftutil/shared_lib.hpp"

int main(int argc, char **argv)
{
	shiftutil::shared_lib EngineCoreLib("VEngineCore");
	
	if(!EngineCoreLib)
		return EXIT_FAILURE;
	
	auto fnGetEngineCore{EngineCoreLib.GetExport<pfnGetEngineCore>("GetEngineCore")};
	
	if(!fnGetEngineCore)
		return EXIT_FAILURE;
	
	auto pEngine{fnGetEngineCore()};
	
	if(!pEngine)
		return EXIT_FAILURE;
	
	IEngineCore::InitParams VEngineInitParams{};
	
	pEngine->Init(VEngineInitParams);
	
	while(true)
		pEngine->Frame();
	
	pEngine->Shutdown();
	
	return EXIT_SUCCESS;
};