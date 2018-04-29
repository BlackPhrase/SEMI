#include "ListenServerMode.hpp"
#include "DedicatedServerMode.hpp"
#include "DedicatedClientMode.hpp"

//CListenServerMode::CListenServerMode() = default;
CListenServerMode::~CListenServerMode() = default;

void CListenServerMode::Init(ICoreEnv *apCoreEnv)
{
	mpDedicatedServer->Init(apCoreEnv);
	mpDedicatedClient->Init(apCoreEnv);
};

void CListenServerMode::Shutdown()
{
	mpDedicatedServer->Shutdown();
	mpDedicatedClient->Shutdown();
};

void CListenServerMode::Frame(float afTimeStep)
{
	mpDedicatedServer->Frame(afTimeStep);
	mpDedicatedClient->Frame(afTimeStep);
};