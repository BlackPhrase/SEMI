/// @file

#include "EngineEnv.hpp"

CEngineEnv::CEngineEnv(ILogger *apLogger, ICmdRegistry *apCmdRegistry, ICvarRegistry *apCvarRegistry, 
	IInputEventDispatcher *apInputEventDispatcher, IPhysics *apPhysics, IResourceManager *apResourceManager)
	: mpLogger(apLogger), mpCmdRegistry(apCmdRegistry), mpCvarRegistry(apCvarRegistry), 
	mpInputEventDispatcher(apInputEventDispatcher), mpPhysics(apPhysics), mpResourceManager(apResourceManager){}
CEngineEnv::~CEngineEnv() = default;