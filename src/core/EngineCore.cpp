#include "EngineCore.hpp"
#include "IEngineExecStrategy.hpp"
#include "vengine/IEngineServer.hpp"
#include "vengine/IEngineClient.hpp"

CEngineCore::CEngineCore() = default;
CEngineCore::~CEngineCore() = default;

void CEngineCore::Init(const InitParams &aInitParams)
{
	switch(aInitParams.Mode)
	{
	case Mode::ListenServer:
		mpExecMode = 
	case Mode::DedicatedServer:
		mpExecMode =
	case Mode::DedicatedClient:
		mpExecMode =
		break;
	};
	
	mpExecMode->Init();
};

void CEngineCore::Shutdown()
{
	mpExecMode->Shutdown();
};

void CEngineCore::Frame()
{
	mpExecMode->Frame();
};