/// @file

#include <cstdlib>

#include "core/ICoreEnv.hpp"
#include "EngineClient.hpp"
#include "RenderWindowGLFW.hpp"

#include "core/ICvarRegistry.hpp"
#include "core/ICvar.hpp"

CEngineClient::CEngineClient() = default;
CEngineClient::~CEngineClient() = default;

bool CEngineClient::Init(ICoreEnv *apCoreEnv)
{
	mpCoreEnv = apCoreEnv;
	
	mpMainWindow = std::make_unique<CRenderWindowGLFW>(); // TODO: Use IRenderWindow interface
	
	if(!mpMainWindow->Init(1280, 600, "V-Engine"))
		exit(EXIT_FAILURE); // std::runtime_error("Failed to initialize the main window!");
	
	apCoreEnv->GetCvarRegistry()->Register("cl_timeout", "60");
	
	printf("\"cl_timeout\" is \"%s\"\n", apCoreEnv->GetCvarRegistry()->Find("cl_timeout")->GetValue());
	return true;
};

void CEngineClient::Shutdown()
{
	mpMainWindow->Shutdown(); // TODO: remove
};

void CEngineClient::Frame()
{
	if(mpMainWindow->WantClose())
		mpCoreEnv->Stop(); //SendCmd("stop"); // quit/exit
	
	mpMainWindow->Update();
};