/// @file

#pragma once

#include "server/IServerEnv.hpp"

class CEngineEnv final : public IEngineEnv
{
public:
	CEngineEnv(ICmdRegistry *apCmdRegistry, ICvarRegistry *apCvarRegistry, IPhysics *apPhysics);
	~CEngineEnv();
	
	ICmdRegistry *GetCmdRegistry() const override {return mpCmdRegistry;}
	ICvarRegistry *GetCvarRegistry() const override {return mpCvarRegistry;}
	
	IPhysics *GetPhysics() const override {return mpPhysics;}
private:
	ICmdRegistry *mpCmdRegistry{nullptr};
	ICvarRegistry *mpCvarRegistry{nullptr};
	IPhysics *mpPhysics{nullptr};
};