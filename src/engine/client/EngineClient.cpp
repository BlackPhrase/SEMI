/// @file

#include <cstdlib>
#include <cstdio>

#include "konbini/shared_lib.hpp"

#include "EngineClient.hpp"
#include "EngineEnv.hpp"
#include "core/ICoreEnv.hpp"
#include "clientgame/IClientGame.hpp"
#include "InputEventDispatcher.hpp"
#include "input/IInput.hpp"
#include "sound/ISound.hpp"
#include "RenderWindowGLFW.hpp"

#include "core/ICvarRegistry.hpp"
#include "core/ICmdProcessor.hpp"
#include "core/ICvar.hpp"
#include "core/IConfig.hpp"

#include "TestInputEventListener.hpp"

CEngineClient::CEngineClient() = default;
CEngineClient::~CEngineClient() = default;

bool CEngineClient::Init(ICoreEnv *apCoreEnv)
{
	if(!apCoreEnv)
		return false;
	
	mpCoreEnv = apCoreEnv;
	
	mpInputEventDispatcher = std::make_unique<CInputEventDispatcher>();
	
	static std::unique_ptr<CTestInputEventListener> pTestInputEventListener = std::make_unique<CTestInputEventListener>();
	mpInputEventDispatcher->AddListener(pTestInputEventListener.get());
	
	mpEnv = std::make_unique<CEngineEnv>(mpCoreEnv->GetLogger(), nullptr, mpCoreEnv->GetCvarRegistry()/*nullptr*/, mpInputEventDispatcher.get(), mpCoreEnv->GetPhysics(), nullptr);
	
	mpMainWindow = std::make_unique<CRenderWindowGLFW>(mpInputEventDispatcher.get());
	
	if(!mpMainWindow->Init(atoi(mpCoreEnv->GetConfig()->GetString("Graphics:Width")), atoi(mpCoreEnv->GetConfig()->GetString("Graphics:Height")), "V-Engine"))
		exit(EXIT_FAILURE); // std::runtime_error("Failed to initialize the main window!");
	
	///////////////////////////////////////////////////////////////
	
	//if(!InitInput())
		//return false;
	
	//if(!mpInput->Init(mpCoreEnv))
	//return false;

	//static auto pTestInputEventListener{std::make_unique<CTestInputEventListener>(mpCoreEnv)};
	//mpInput->AddEventListener(pTestInputEventListener.get());
	
	///////////////////////////////////////////////////////////////
	
	if(!InitSound())
		return false;
	
	if(!mpSound->Init(0, 0, 0))
		return false;
	
	///////////////////////////////////////////////////////////////
	
	if(!InitGame(/*"VEngineClientGame"*/))
		return false;
	
	if(!mpGame->Init(mpEnv.get()))
		return false;
	
	apCoreEnv->GetCvarRegistry()->Add("cl_timeout", "60");
	
	printf("\"cl_timeout\" is \"%s\"\n", apCoreEnv->GetCvarRegistry()->Find("cl_timeout")->GetValue());
	return true;
};

void CEngineClient::Shutdown()
{
	mpGame->Shutdown();
	mpSound->Shutdown();
	//mpInput->Shutdown();
	mpMainWindow->Shutdown(); // TODO: remove
};

void CEngineClient::Frame()
{
	if(mpMainWindow->WantClose())
		mpCoreEnv->Stop(); //SendCmd("stop"); // quit/exit
	
	//mpCoreEnv->GetCmdProcessor()->AppendText("test");
	//mpCoreEnv->GetCmdProcessor()->AppendText("unknown-cmd-test");
	
	mpMainWindow->Update();
	//mpInput->Update();
	mpSound->Update();
	mpGame->Frame();
};

bool CEngineClient::InitInput()
bool CEngineClient::InitGame(/*const std::string &asName*/) // TODO: should be allow this?
{
	static konbini::shared_lib InputLib("VEngineInput");
	static shiftutil::shared_lib GameLib("VEngineClientGame");
	
	if(!InputLib)
		return false;
	
	auto fnGetInput{InputLib.getexportfunc<pfnGetInput>("GetInput")};
	
	if(!fnGetInput)
		return false;
	
	mpInput = fnGetInput(IInput::Version, *mpCoreEnv);
	
	if(!mpInput)
		return false;
	
	return true;
};

	//if(!GameLib)
		//return false;
bool CEngineClient::InitSound()
{
	static konbini::shared_lib SoundLib("VEngineSound");
	
	if(!SoundLib)
		return false;
	
	auto fnGetSound{SoundLib.getexportfunc<pfnGetSound>("GetSound")};
	
	if(!fnGetSound)
		return false;
	
	mpSound = fnGetSound(ISound::Version, *mpCoreEnv);
	
	if(!mpSound)
		return false;
	
	return true;
};
	
	auto fnGetClientGame{GameLib.getexportfunc<pfnGetClientGame>("GetClientGame")};
	
	if(!fnGetClientGame)
		return false;
	
	mpGame = fnGetClientGame(IClientGame::Version);
	
	if(!mpGame)
		return false;
	
	return true;
};