/// @file

#include "EngineEnv.hpp"

CEngineEnv::CEngineEnv(ILogger *apLogger, ICmdRegistry *apCmdRegistry, ICvarRegistry *apCvarRegistry, IPhysics *apPhysics)
	: mpLogger(apLogger), mpCmdRegistry(apCmdRegistry), mpCvarRegistry(apCvarRegistry), mpPhysics(apPhysics){}
CEngineEnv::~CEngineEnv() = default;