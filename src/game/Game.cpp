/// @file

#include <cstdio>

#include "Game.hpp"

#include "server/IServerEnv.hpp"

#include "core/ICvar.hpp"
#include "core/ICvarRegistry.hpp"

CGame::CGame() = default;
CGame::~CGame() = default;

bool CGame::Init(IEngineEnv *apEngineEnv)
{
	if(!apEngineEnv)
		return false;
	
	ICvar *pCvar_GameDLL = apEngineEnv->GetCvarRegistry()->Add("sv_gamedll", "1", "Just a test cvar indicating that game dll is working!");
	
	apEngineEnv->GetLogger()->Message("\"%s\" is \"%s\" (def: %s | desc: %s)\n", pCvar_GameDLL->GetName(), pCvar_GameDLL->GetValue(), pCvar_GameDLL->GetDefValue(), pCvar_GameDLL->GetDescription());
	return true;
};

void CGame::Shutdown()
{
};

void CGame::Frame()
{
};