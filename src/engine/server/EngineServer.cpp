/// @file

#include <cstdio>

#include "shiftutil/shared_lib.hpp"
#include "EngineServer.hpp"
#include "core/ICoreEnv.hpp"
#include "game/IGame.hpp"

#include "core/ICvarRegistry.hpp"
#include "core/ICvar.hpp"
#include "core/ICmdRegistry.hpp"

void TestCmd_f()
{
	printf("TestCmd_f\n");
};

CEngineServer::CEngineServer() = default;
CEngineServer::~CEngineServer() = default;

bool CEngineServer::Init(ICoreEnv *apCoreEnv)
{
	if(!InitGame(/*"VEngineGame"*/))
		return false;
	
	//mpServerEnv = new CServerEnv();
	
	if(!mpGame->Init(nullptr)) // TODO
		return false;
	
	apCoreEnv->GetCvarRegistry()->Register("sv_pure", "1");
	
	printf("\"sv_pure\" is \"%s\"\n", apCoreEnv->GetCvarRegistry()->Find("sv_pure")->GetValue());
	
	apCoreEnv->GetCmdRegistry()->Register("test", TestCmd_f);
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