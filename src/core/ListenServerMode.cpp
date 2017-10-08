#include "ListenServerMode.hpp"

CListenServerMode::CListenServerMode() = default;
CListenServerMode::~CListenServerMode() = default;

void CListenServerMode::Init()
{
	mpDedicatedServer->Init();
	mpDedicatedClient->Init();
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