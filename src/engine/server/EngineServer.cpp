/// @file

#include "EngineServer.hpp"
#include "game/IGame.hpp"

CEngineServer::CEngineServer() = default;
CEngineServer::~CEngineServer() = default;

void CEngineServer::Init()
{
	if(!InitGame("VEngineGame"))
		return;
	
	if(!mpGame->Init())
		return;
};

void CEngineServer::Shutdown()
{
	mpGame->Shutdown();
};

void CEngineServer::Frame()
{
	mpGame->Frame();
};

bool CEngineServer::InitGame(const std::string &asName)
{
	static shiftutil::shared_lib GameLib(asName.c_str());
	
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