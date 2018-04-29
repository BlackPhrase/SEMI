/// @file

#include "Game.hpp"

CGame::CGame() = default;
CGame::~CGame() = default;

bool CGame::Init(IEngineEnv *apEngineEnv)
{
	return true;
};

void CGame::Shutdown()
{
};

void CGame::Frame()
{
};