/// @file

#pragma once

#include "server/IServerEnv.hpp"

class CEngineEnv final : public IEngineEnv
{
public:
	CEngineEnv(ILogger *apLogger, ICmdRegistry *apCmdRegistry, ICvarRegistry *apCvarRegistry, IPhysics *apPhysics);
	~CEngineEnv();
	
	ILogger *GetLogger() const override {return mpLogger;}
	
	ICmdRegistry *GetCmdRegistry() const override {return mpCmdRegistry;}
	ICvarRegistry *GetCvarRegistry() const override {return mpCvarRegistry;}
	
	IPhysics *GetPhysics() const override {return mpPhysics;}
private:
	ILogger *mpLogger{nullptr};
	ICmdRegistry *mpCmdRegistry{nullptr};
	ICvarRegistry *mpCvarRegistry{nullptr};
	IPhysics *mpPhysics{nullptr};
};