/// @file

#pragma once

#include "clientgame/IClientGame.hpp"

class CClientGame final : public IClientGame
{
public:
	CClientGame();
	~CClientGame();
	
	bool Init(IEngineEnv *apEngineEnv) override;
	void Shutdown() override;
	
	void Frame() override;
};