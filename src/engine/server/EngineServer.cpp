/// @file

#include <cstdio>

#include "shiftutil/shared_lib.hpp"

#include "EngineServer.hpp"
#include "EngineEnv.hpp"
#include "core/ICoreEnv.hpp"
#include "game/IGame.hpp"

#include "core/ICvarRegistry.hpp"
#include "core/ICvar.hpp"
#include "core/ICmdRegistry.hpp"

void TestCmd_f(const ICmdArgs &apArgs)
{
	printf("TestCmd_f\n");
};

CEngineServer::CEngineServer() = default;
CEngineServer::~CEngineServer() = default;

bool CEngineServer::Init(ICoreEnv *apCoreEnv)
{
	if(!apCoreEnv)
		return false;
	
	mpCoreEnv = apCoreEnv;
	
	mpEnv = std::make_unique<CEngineEnv>(mpCoreEnv->GetLogger(), nullptr, mpCoreEnv->GetCvarRegistry()/*nullptr*/, mpCoreEnv->GetPhysics());
	
	if(!InitGame(/*"VEngineGame"*/))
		return false;
	
	if(!mpGame->Init(mpEnv.get()))
		return false;
	
	apCoreEnv->GetCvarRegistry()->Add("sv_pure", "1");
	
	printf("\"sv_pure\" is \"%s\"\n", apCoreEnv->GetCvarRegistry()->Find("sv_pure")->GetValue());
	
	apCoreEnv->GetCmdRegistry()->Add("test", TestCmd_f);
	return true;
};

void CEngineServer::Shutdown()
{
	mpGame->Shutdown();
};

void CEngineServer::Frame()
{
	mpGame->Frame();
};

bool CEngineServer::InitGame(/*const std::string &asName*/) // TODO: should be allow this?
{
	static shiftutil::shared_lib GameLib("VEngineGame");
	
	//if(!GameLib)
		//return false;
	
	auto fnGetGame{GameLib.getexportfunc<pfnGetGame>("GetGame")};
	
	if(!fnGetGame)
		return false;
	
	mpGame = fnGetGame(IGame::Version);
	
	if(!mpGame)
		return false;
	
	return true;
};