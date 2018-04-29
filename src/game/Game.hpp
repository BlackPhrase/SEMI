/// @file

#pragma once

#include "game/IGame.hpp"

class CGame final : public IGame
{
public:
	CGame();
	~CGame();
	
	bool Init(IEngineEnv *apEngineEnv) override;
	void Shutdown() override;
	
	void Frame() override;
};