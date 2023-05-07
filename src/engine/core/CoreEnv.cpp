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

#include "CoreEnv.hpp"

#include <core/IEngineCore.hpp>

CCoreEnv::CCoreEnv(IEngineCore *apCore, ISystem *apSystem, IMemoryManager *apMemoryManager, IConfig *apConfig, IEngineModuleContainer *apEngineModuleContainer)
	: mpCore(apCore), mpSystem(apSystem), mpMemoryManager(apMemoryManager), mpConfig(apConfig), mpEngineModuleContainer(apEngineModuleContainer){}

CCoreEnv::~CCoreEnv() = default;

void CCoreEnv::Stop()
{
	mpCore->RequestClose();
};

/*
void CCoreEnv::SendCmd(const char *asText)
{
	//mpCmdProcessor->Insert(asText);
};
*/