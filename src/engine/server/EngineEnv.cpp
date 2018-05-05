/// @file

#include "EngineEnv.hpp"

CEngineEnv::CEngineEnv(ICmdRegistry *apCmdRegistry, ICvarRegistry *apCvarRegistry, IPhysics *apPhysics)
	: mpCmdRegistry(apCmdRegistry), mpCvarRegistry(apCvarRegistry), mpPhysics(apPhysics){}
CEngineEnv::~CEngineEnv() = default;