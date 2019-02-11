/// @file

#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#endif

#include "konbini/shared_lib.hpp"
#include "core/IEngineCore.hpp"

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
	
	// Allow to start the engine in dedicated client mode for developers
#ifdef VENGINE_DEV
	for(int i = 0; i < argc; ++i)
		if(!strcmp(argv[i], "-dedicatedclient"))
			VEngineInitParams.ExecMode = IEngineCore::Mode::DedicatedClient;
#endif

	pEngine->Init(VEngineInitParams);
	
	while(pEngine->Frame()) // TODO: geez...
		;
	
	pEngine->Shutdown();
	
	return EXIT_SUCCESS;
};

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return main(__argc, __targv);
};
#endif