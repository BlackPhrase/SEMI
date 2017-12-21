#include "DedicatedClientMode.hpp"
#include "ModuleLoader.hpp"
#include "vengine/IEngineClient.hpp"

CDedicatedClientMode::CDedicatedClientMode() = default;
CDedicatedClientMode::~CDedicatedClientMode() = default;

void CDedicatedClientMode::Init(IEngineCore *apCore)
{
	auto EngClientModule{CModuleLoader::LoadModule("VEngineClient")};
	
	auto EngClientFactory{EngClientModule->GetFactory()};
	
	mpEngClient = EngClientFactory->GetInterface<IEngineClient>(IEngineClient::Version);
	
	mpEngClient->Init(apCore);
};

void CDedicatedClientMode::Shutdown()
{
	mpEngClient->Shutdown();
};

void CDedicatedClientMode::Frame()
{
	mpEngClient->Frame();
};