#include "ListenServerMode.hpp"
#include "DedicatedServerMode.hpp"
#include "DedicatedClientMode.hpp"

//CListenServerMode::CListenServerMode() = default;
CListenServerMode::~CListenServerMode() = default;

void CListenServerMode::Init(IEngineCore *apCore)
{
	mpDedicatedServer->Init(apCore);
	mpDedicatedClient->Init(apCore);
};

void CListenServerMode::Shutdown()
{
	mpDedicatedServer->Shutdown();
	mpDedicatedClient->Shutdown();
};

void CListenServerMode::Frame()
{
	mpDedicatedServer->Frame();
	mpDedicatedClient->Frame();
};