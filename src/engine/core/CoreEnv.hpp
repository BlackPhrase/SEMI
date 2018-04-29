/// @file

#pragma once

#include "core/ICoreEnv.hpp"

struct IEngineCore;

class CCoreEnv final : public ICoreEnv
{
public:
	CCoreEnv(IEngineCore *apCore, ICvarRegistry *apCvarRegistry, ICmdRegistry *apCmdRegistry, IPhysics *apPhysics, INetwork *apNetwork);
	~CCoreEnv();
	
	ICvarRegistry *GetCvarRegistry() const override {return mpCvarRegistry;}
	ICmdRegistry *GetCmdRegistry() const override {return mpCmdRegistry;}
	
	IPhysics *GetPhysics() const override {return mpPhysics;}
	INetwork *GetNetwork() const override {return mpNetwork;}
	
	void Stop() override;
	
	//void SendCmd(const char *asText) override;
private:
	IEngineCore *mpCore{nullptr};

	ICvarRegistry *mpCvarRegistry{nullptr};
	ICmdRegistry *mpCmdRegistry{nullptr};
	IPhysics *mpPhysics{nullptr};
	INetwork *mpNetwork{nullptr};
};