/*
 * This file is part of V-Engine
 *
 * Copyright 2017-2018, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#pragma once

#include "IEngineExecMode.hpp"

struct IEngineServer;

class CDedicatedServerMode final : public IEngineExecMode
{
public:
	CDedicatedServerMode();
	~CDedicatedServerMode();
	
	void Init(ICoreEnv *apCoreEnv) override;
	void Shutdown() override;
	
	void Frame(float afTimeStep) override;
private:
	IEngineServer *mpEngServer{nullptr};
};