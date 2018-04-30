/// @file

#pragma once

#include "client/IClientEnv.hpp"

class CEngineEnv final : public IEngineEnv
{
public:
	CEngineEnv(ICmdRegistry *apCmdRegistry, ICvarRegistry *apCvarRegistry, IInputEventDispatcher *apInputEventDispatcher, IPhysics *apPhysics, IResourceManager *apResourceManager);
	~CEngineEnv();
	
	ICvarRegistry *GetCvarRegistry() const override {return mpCvarRegistry;}
	ICmdRegistry *GetCmdRegistry() const override {return mpCmdRegistry;}
	
	IInputEventDispatcher *GetInputEventDispatcher() const override {return mpInputEventDispatcher;}
	
	IPhysics *GetPhysics() const override {return mpPhysics;}
	
	IResourceManager *GetResourceManager() const override {return mpResourceManager;}
private:
	ICmdRegistry *mpCmdRegistry{nullptr};
	ICvarRegistry *mpCvarRegistry{nullptr};
	IInputEventDispatcher *mpInputEventDispatcher{nullptr};
	IPhysics *mpPhysics{nullptr};
	IResourceManager *mpResourceManager{nullptr};
};