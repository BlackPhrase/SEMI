#include "EngineCore.hpp"
#include "IEngineExecStrategy.hpp"
#include "vengine/IEngineServer.hpp"
#include "vengine/IEngineClient.hpp"

CEngineCore::CEngineCore() = default;
CEngineCore::~CEngineCore() = default;

void CEngineCore::Init(const IEngineCore::InitParams &aInitParams)
{
	switch(aInitParams.ExecMode)
	{
	case Mode::ListenServer:
		//mpExecMode = 
		break;
	case Mode::DedicatedServer:
		//mpExecMode =
		break;
	case Mode::DedicatedClient:
		//mpExecMode =
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