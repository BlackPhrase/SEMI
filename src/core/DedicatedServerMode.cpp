#include "DedicatedServerMode.hpp"
#include "ModuleLoader.hpp"
#include "vengine/IEngineServer.hpp"

CDedicatedServerMode::CDedicatedServerMode() = default;
CDedicatedServerMode::~CDedicatedServerMode() = default;

void CDedicatedServerMode::Init(IEngineCore *apCore)
{
	auto EngServerModule{CModuleLoader::LoadModule("VEngineServer")};
	
	auto EngServerFactory{EngServerModule->GetFactory()};
	
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