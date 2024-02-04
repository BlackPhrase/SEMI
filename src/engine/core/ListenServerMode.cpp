/*
 * This file is part of V-Engine
 *
 * Copyright 2017-2018, 2024 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

#include "ListenServerMode.hpp"
#include "DedicatedServerMode.hpp"
#include "DedicatedClientMode.hpp"

//CListenServerMode::CListenServerMode() = default;
CListenServerMode::~CListenServerMode() = default;

void CListenServerMode::Init(ICoreEnv *apCoreEnv)
{
	mpDedicatedServer->Init(apCoreEnv);
	mpDedicatedClient->Init(apCoreEnv);
};

void CListenServerMode::Shutdown()
{
	mpDedicatedServer->Shutdown();
	mpDedicatedClient->Shutdown();
};

void CListenServerMode::Frame(float afTimeStep)
{
	mpDedicatedServer->Frame(afTimeStep);
	mpDedicatedClient->Frame(afTimeStep);
};