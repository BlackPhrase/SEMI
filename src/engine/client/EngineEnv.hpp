/// @file

#pragma once

#include "client/IClientEnv.hpp"

class CEngineEnv final : public IEngineEnv
{
public:
	CEngineEnv(ILogger *apLogger, ICmdRegistry *apCmdRegistry, ICvarRegistry *apCvarRegistry, IInputEventDispatcher *apInputEventDispatcher, IPhysics *apPhysics, IResourceManager *apResourceManager);
	~CEngineEnv();
	
	ILogger *GetLogger() const override {return mpLogger;}
	
	ICmdRegistry *GetCmdRegistry() const override {return mpCmdRegistry;}
	ICvarRegistry *GetCvarRegistry() const override {return mpCvarRegistry;}
	
	IInputEventDispatcher *GetInputEventDispatcher() const override {return mpInputEventDispatcher;}
	
	IPhysics *GetPhysics() const override {return mpPhysics;}
	
	IResourceManager *GetResourceManager() const override {return mpResourceManager;}
private:
	ILogger *mpLogger{nullptr};
	ICmdRegistry *mpCmdRegistry{nullptr};
	ICvarRegistry *mpCvarRegistry{nullptr};
	IInputEventDispatcher *mpInputEventDispatcher{nullptr};
	IPhysics *mpPhysics{nullptr};
	IResourceManager *mpResourceManager{nullptr};
};