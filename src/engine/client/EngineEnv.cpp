/// @file

#include "EngineEnv.hpp"

CEngineEnv::CEngineEnv(ICmdRegistry *apCmdRegistry, ICvarRegistry *apCvarRegistry, IInputEventDispatcher *apInputEventDispatcher, IPhysics *apPhysics, IResourceManager *apResourceManager)
	: mpCmdRegistry(apCmdRegistry), mpCvarRegistry(apCvarRegistry), mpInputEventDispatcher(apInputEventDispatcher), mpPhysics(apPhysics), mpResourceManager(apResourceManager){}
CEngineEnv::~CEngineEnv() = default;