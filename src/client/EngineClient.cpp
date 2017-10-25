#include <cstdlib>
#include "EngineClient.hpp"
#include "RenderWindowGLFW.hpp"
#include "vengine/IEngineCore.hpp"

CEngineClient::CEngineClient() = default;
CEngineClient::~CEngineClient() = default;

void CEngineClient::Init(IEngineCore *apCore)
{
	mpCore = apCore;
	
	mpMainWindow = std::make_unique<CRenderWindowGLFW>(); // TODO: Use IRenderWindow interface
	
	if(!mpMainWindow->Init(1280, 600, "V-Engine"))
		exit(EXIT_FAILURE); // std::runtime_error("Failed to initialize the main window!");
};

void CEngineClient::Shutdown()
{
	mpMainWindow->Shutdown(); // TODO: remove
};

void CEngineClient::Frame()
{
	if(mpMainWindow->WantClose())
		mpCore->Stop(); //SendCmd("stop"); // quit/exit
	
	mpMainWindow->Update();
};