/// @file

#include <cstdio>

#include "ClientGame.hpp"

#include "client/IClientEnv.hpp"

#include "core/ICvar.hpp"
#include "core/ICvarRegistry.hpp"

CClientGame::CClientGame() = default;
CClientGame::~CClientGame() = default;

bool CClientGame::Init(IEngineEnv *apEngineEnv)
{
	if(!apEngineEnv)
		return false;
	
	ICvar *pCvar_ClientDLL = apEngineEnv->GetCvarRegistry()->Add("cl_gamedll", "1", "Just a test cvar indicating that client game dll is working!");
	
	printf("\"%s\" is \"%s\" (def: %s | desc: %s)\n", pCvar_ClientDLL->GetName(), pCvar_ClientDLL->GetValue(), pCvar_ClientDLL->GetDefValue(), pCvar_ClientDLL->GetDescription());
	return true;
};

void CClientGame::Shutdown()
{
};

void CClientGame::Frame()
{
};