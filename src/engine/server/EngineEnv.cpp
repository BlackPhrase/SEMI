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

#include "EngineEnv.hpp"

CEngineEnv::CEngineEnv(ILogger *apLogger, ICmdRegistry *apCmdRegistry, ICvarRegistry *apCvarRegistry, IPhysics *apPhysics, IScript *apScript, INetServer *apServer)
	: mpLogger(apLogger), mpCmdRegistry(apCmdRegistry), mpCvarRegistry(apCvarRegistry), mpPhysics(apPhysics), mpScript(apScript), mpServer(apServer){}
CEngineEnv::~CEngineEnv() = default;