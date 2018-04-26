/// @file

#include <cstdlib>

#include "EngineCore.hpp"
//#include "Timer.hpp"
#include "network/INetwork.hpp"
#include "server/IEngineServer.hpp"
#include "client/IEngineClient.hpp"

#include "DedicatedServerMode.hpp"
#include "DedicatedClientMode.hpp"
#include "ListenServerMode.hpp"

CEngineCore::CEngineCore() = default;
CEngineCore::~CEngineCore() = default;

bool CEngineCore::Init(const IEngineCore::InitParams &aInitParams)
{
	//using namespace std::chrono_literals;
	
	//mpTimer = std::make_unique<CTimer>(500ms); // TODO: THAT'S TOOO MUUUUUUUUUUUUUUUUUUUUUUUUUUUUCCH
	
	if(!InitPhysics())
		return false;
	
	bool bUseNetworking{true};
	
	if(bUseNetworking)
		if(!InitNetworking())
			return false;
	else
		mpNetwork = new CNetworkNull(); // TODO
	
	switch(aInitParams.ExecMode)
	{
	case Mode::ListenServer:
		mpExecMode = std::make_unique<CListenServerMode>(new CDedicatedServerMode(), new CDedicatedClientMode()); // TODO: bad
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
	//mpCmdProcessor->Insert(asText);
};

bool CEngineCore::InitPhysics()
{
	static shiftutil::shared_lib PhysicsLib("VEnginePhysics");
	
	//if(!PhysicsLib)
		//return false;
	
	auto fnGetPhysics{PhysicsLib.getexportfunc<pfnGetPhysics>("GetPhysics")};
	
	if(!fnGetPhysics)
		return false;
	
	mpPhysics = fnGetPhysics(IPhysics::Version);
	
	if(!mpPhysics)
		return false;
	
	return true;
};

bool CEngineCore::InitNetworking()
{
	static shiftutil::shared_lib NetworkLib("VEngineNetwork");
	
	//if(!NetworkLib)
		//return false;
	
	auto fnGetNetwork{NetworkLib.getexportfunc<pfnGetNetwork>("GetNetwork")};
	
	if(!fnGetNetwork)
		return false;
	
	mpNetwork = fnGetNetwork(INetwork::Version);
	
	if(!mpNetwork)
		return false;
	
	return true;
};