#include <cstdlib>
#include "EngineCore.hpp"
//#include "Timer.hpp"
#include "vengine/IEngineServer.hpp"
#include "vengine/IEngineClient.hpp"

#include "DedicatedServerMode.hpp"
#include "DedicatedClientMode.hpp"
#include "ListenServerMode.hpp"

CEngineCore::CEngineCore() = default;
CEngineCore::~CEngineCore() = default;

bool CEngineCore::Init(const IEngineCore::InitParams &aInitParams)
{
	//using namespace std::chrono_literals;
	
	//mpTimer = std::make_unique<CTimer>(500ms);
	
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
	
	//mpTimer->SetCallback([this](){mpExecMode->Frame();});
	
	return true;
};

void CEngineCore::Shutdown()
{
	mpExecMode->Shutdown();
};

bool CEngineCore::Frame()
{
	if(!mbShouldStop)
	{
		//mpExecMode->FrameBegin();
		
		//mpTimer->Tick();
		
		//if(mpTimer->WantUpdate())
		//{
			//mpExecMode->Frame();
		//};
		
		//mpExecMode->HandleInput();
		
		mpExecMode->Frame(0.1f);
		
		//mpExecMode->Render();
		
		//mpExecMode->FrameEnd();
		return true;
	};
	
	return false;
};

void CEngineCore::Stop()
{
	mbShouldStop = true;
};

void CEngineCore::SendCmd(const char *asText)
{
};