/// @file

#include "EngineEnv.hpp"

CEngineEnv::CEngineEnv(ILogger *apLogger, ICmdRegistry *apCmdRegistry, ICvarRegistry *apCvarRegistry, IPhysics *apPhysics, IScript *apScript, INetServer *apServer)
	: mpLogger(apLogger), mpCmdRegistry(apCmdRegistry), mpCvarRegistry(apCvarRegistry), mpPhysics(apPhysics), mpScript(apScript), mpServer(apServer){}
CEngineEnv::~CEngineEnv() = default;