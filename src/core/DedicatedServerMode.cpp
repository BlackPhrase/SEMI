#include "DedicatedServerMode.hpp"

CDedicatedServerMode::CDedicatedServerMode() = default;
CDedicatedServerMode::~CDedicatedServerMode() = default;

void CDedicatedServerMode::Init()
{
	EngServerModule = ModuleLoader->LoadModule("VEngineServer");
	
	EngServerFactory = EngServerModule->GetFactory();
	
	mpEngServer = EngServerFactory->GetInterface<IEngineServer>(IEngineServer::Version);
	
	mpEngServer->Init();
};

void CDedicatedServerMode::Shutdown()
{
	mpEngServer->Shutdown();
};

void CDedicatedServerMode::Frame()
{
	mpEngServer->Frame();
};