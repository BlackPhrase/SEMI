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

struct IEngineClient;

class CDedicatedClientMode final : public IEngineExecMode
{
public:
	CDedicatedClientMode();
	~CDedicatedClientMode();
	
	void Init(ICoreEnv *apCoreEnv) override;
	void Shutdown() override;
	
	void Frame(float afTimeStep) override;
private:
	IEngineClient *mpEngClient{nullptr};
};