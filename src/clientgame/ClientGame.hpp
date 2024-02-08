/*
 * This file is part of V-Engine
 *
 * Copyright 2018, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#pragma once

#include <clientgame/IClientGame.hpp>

class CClientGame final : public IClientGame
{
public:
	CClientGame();
	~CClientGame();
	
	bool Init(IEngineEnv *apEngineEnv) override;
	void Shutdown() override;
	
	void Frame() override;
};