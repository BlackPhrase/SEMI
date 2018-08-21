/// @file

#include <cstdlib>
#include <cstdio>

#include "shiftutil/shared_lib.hpp"

#include "EngineClient.hpp"
#include "EngineEnv.hpp"
#include "core/ICoreEnv.hpp"
#include "clientgame/IClientGame.hpp"
#include "InputEventDispatcher.hpp"
#include "RenderWindowGLFW.hpp"

#include "core/ICvarRegistry.hpp"
#include "core/ICmdProcessor.hpp"
#include "core/ICvar.hpp"
#include "core/IConfig.hpp"

#include "client/IInputEventListener.hpp"

class CTestInputEventListener final : public IInputEventListener
{
public:
	CTestInputEventListener() = default;
	~CTestInputEventListener() = default;
	
	void OnKeyPressed(int anKey) override
	{
		printf("Key %d pressed...\n", anKey);
	};
	
	void OnKeyReleased(int anKey) override
	{
		printf("Key %d released...\n", anKey);
	};
};

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
	mpMainWindow->Shutdown(); // TODO: remove
};

void CEngineClient::Frame()
{
	if(mpMainWindow->WantClose())
		mpCoreEnv->Stop(); //SendCmd("stop"); // quit/exit
	
	//mpCoreEnv->GetCmdProcessor()->AppendText("test");
	//mpCoreEnv->GetCmdProcessor()->AppendText("unknown-cmd-test");
	
	mpMainWindow->Update();
	mpGame->Frame();
};

bool CEngineClient::InitGame(/*const std::string &asName*/) // TODO: should be allow this?
{
	static shiftutil::shared_lib GameLib("VEngineClientGame");
	
	//if(!GameLib)
		//return false;
	
	auto fnGetClientGame{GameLib.getexportfunc<pfnGetClientGame>("GetClientGame")};
	
	if(!fnGetClientGame)
		return false;
	
	mpGame = fnGetClientGame(IClientGame::Version);
	
	if(!mpGame)
		return false;
	
	return true;
};