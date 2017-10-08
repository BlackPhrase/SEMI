#include "DedicatedClientMode.hpp"

CDedicatedClientMode::CDedicatedClientMode() = default;
CDedicatedClientMode::~CDedicatedClientMode() = default;

void CDedicatedClientMode::Init()
{
	EngClientModule = ModuleLoader->LoadModule("VEngineClient");
	
	EngClientFactory = EngClientModule->GetFactory();
	
	mpEngClient = EngClientFactory->GetInterface<IEngineClient>(IEngineClient::Version);
	
	mpEngClient->Init();
};

void CDedicatedClientMode::Shutdown()
{
	mpEngClient->Shutdown();
};

void CDedicatedClientMode::Frame()
{
	mpEngClient->Frame();
};