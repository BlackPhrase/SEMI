#include <cstdlib>
#include "EngineCore.hpp"
#include "vengine/IEngineServer.hpp"
#include "vengine/IEngineClient.hpp"

#include "DedicatedServerMode.hpp"
#include "DedicatedClientMode.hpp"
#include "ListenServerMode.hpp"

CEngineCore::CEngineCore() = default;
CEngineCore::~CEngineCore() = default;

void CEngineCore::Init(const IEngineCore::InitParams &aInitParams)
{
	switch(aInitParams.ExecMode)
	{
	case Mode::ListenServer:
		mpExecMode = std::make_unique<CListenServerMode>(new CDedicatedServerMode(), new CDedicatedClientMode());
		break;
	case Mode::DedicatedServer:
		mpExecMode = std::make_unique<CDedicatedServerMode>();
		break;
	case Mode::DedicatedClient:
		mpExecMode = std::make_unique<CDedicatedClientMode>();
		break;
	};
	
	mpExecMode->Init(this);
};

void CEngineCore::Shutdown()
{
	mpExecMode->Shutdown();
};

void CEngineCore::Frame()
{
	if(!mbShouldStop)
		mpExecMode->Frame();
};

void CEngineCore::Stop()
{
	mbShouldStop = true;
};

void CEngineCore::SendCmd(const char *asText)
{
};