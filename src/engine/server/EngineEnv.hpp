/// @file

#pragma once

#include "server/IServerEnv.hpp"

class CEngineEnv final : public IEngineEnv
{
public:
	CEngineEnv(ILogger *apLogger, ICmdRegistry *apCmdRegistry, ICvarRegistry *apCvarRegistry, IPhysics *apPhysics, IScript *apScript, INetServer *apServer);
	~CEngineEnv();
	
	ILogger *GetLogger() const override {return mpLogger;}
	
	ICmdRegistry *GetCmdRegistry() const override {return mpCmdRegistry;}
	ICvarRegistry *GetCvarRegistry() const override {return mpCvarRegistry;}
	
	IPhysics *GetPhysics() const override {return mpPhysics;}
	
	IScript *GetScript() const override {return mpScript;}
	
	INetServer *GetServer() const override {return mpServer;} // TODO: GetNetServer?
private:
	ILogger *mpLogger{nullptr};
	ICmdRegistry *mpCmdRegistry{nullptr};
	ICvarRegistry *mpCvarRegistry{nullptr};
	IPhysics *mpPhysics{nullptr};
	IScript *mpScript{nullptr};
	INetServer *mpServer{nullptr};
};