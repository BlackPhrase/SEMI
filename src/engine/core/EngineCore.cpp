/// @file

#include <cstdlib>

#include "shiftutil/shared_lib.hpp"

#include "EngineCore.hpp"
#include "CoreEnv.hpp"
//#include "Timer.hpp"
#include "MemoryManager.hpp"
#include "Logger.hpp"
#include "Config.hpp"
#include "CvarRegistry.hpp"
#include "CmdRegistry.hpp"
#include "CmdProcessor.hpp"
#include "ThreadPool.hpp"

#include "network/INetwork.hpp"
#include "physics/IPhysics.hpp"
#include "script/IScript.hpp"

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
	
	mpMemoryManager = std::make_unique<CMemoryManager>();
	mpLogger = std::make_unique<CLogger>();
	mpConfig = std::make_unique<CConfig>();
	
	// Do we have any last config saved?
	if(!mpConfig->LoadFromFile("VEngineLast.ini"))
		mpConfig->LoadFromFile("VEngineDefault.ini");
	
	mpCvarRegistry = std::make_unique<CCvarRegistry>();
	mpCmdRegistry = std::make_unique<CCmdRegistry>();
	
	mpCmdProcessor = std::make_unique<CCmdProcessor>(mpCmdRegistry.get());
	
	// Initialize the thread pool (worker threads)
	mpThreadPool = std::make_unique<CThreadPool>(atoi(mpConfig->GetString("General:WorkerThreads")));
	
	//if(!InitPhysics())
		//return false;
	
	bool bUseNetworking{false};
	
	if(bUseNetworking)
		if(!InitNetworking())
			return false;
	//else
		//mpNetwork = new CNetworkNull(); // TODO
	
	if(!InitScripting())
		return false;
	
	mpEnv = std::make_unique<CCoreEnv>(this, mpMemoryManager.get(), mpLogger.get(), mpConfig.get(), mpCvarRegistry.get(), mpCmdRegistry.get(), mpCmdProcessor.get(), mpPhysics, mpNetwork);
	
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
	
	mpExecMode->Init(mpEnv.get());
	
	mpScript->CallFunc("OnStart");
	
	//mpTimer->SetCallback([this](){mpExecMode->Frame();});
	
	return true;
};

void CEngineCore::Shutdown()
{
	mpScript->CallFunc("OnExit");
	mpExecMode->Shutdown();
	mpConfig->SaveToFile("VEngineLast.ini"); // TODO: shouldn't it be above the call to execution mode?
};

bool CEngineCore::Frame()
{
	if(mbCloseRequested)
		return false;
	
	//mpExecMode->FrameBegin(); // mpEventDispatcher->DispatchEvent(Event::FrameBegin);
	
	mpCmdProcessor->ExecPending();
	
	mpScript->CallFunc("OnFrame");
	
	//mpTimer->Tick();
	
	//if(mpTimer->WantUpdate())
	//{
		//mpExecMode->Frame();
	//};
	
	//mpExecMode->HandleInput();
	
	mpExecMode->Frame(0.1f);
	
	//mpExecMode->Render();
	
	//mpExecMode->FrameEnd(); // mpEventDispatcher->DispatchEvent(Event::FrameEnd);
	
	return true;
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

bool CEngineCore::InitScripting()
{
	static shiftutil::shared_lib ScriptLib("VEngineScript");
	
	//if(!ScriptLib)
		//return false;
	
	auto fnGetScript{ScriptLib.getexportfunc<pfnGetScript>("GetScript")};
	
	if(!fnGetScript)
		return false;
	
	mpScript = fnGetScript(IScript::Version);
	
	if(!mpScript)
		return false;
	
	if(!mpScript->Init())
		return false;
	
	return true;
};