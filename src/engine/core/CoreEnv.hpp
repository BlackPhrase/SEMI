/// @file

#pragma once

#include "core/ICoreEnv.hpp"

struct IEngineCore;

class CCoreEnv final : public ICoreEnv
{
public:
	CCoreEnv(IEngineCore *apCore, ICommandLine *apCommandLine, IMemoryManager *apMemoryManager, ILogger *apLogger, IConfig *apConfig,
			ICvarRegistry *apCvarRegistry, ICmdRegistry *apCmdRegistry, ICmdProcessor *apCmdProcessor, IPhysics *apPhysics, INetwork *apNetwork);
	~CCoreEnv();
	
	ICommandLine *GetCommandLine() const override {return mpCommandLine;}
	IMemoryManager *GetMemoryManager() const override {return mpMemoryManager;}
	ILogger *GetLogger() const override {return mpLogger;}
	IConfig *GetConfig() const override {return mpConfig;}
	
	ICvarRegistry *GetCvarRegistry() const override {return mpCvarRegistry;}
	ICmdRegistry *GetCmdRegistry() const override {return mpCmdRegistry;}
	
	ICmdProcessor *GetCmdProcessor() const override {return mpCmdProcessor;}
	
	IPhysics *GetPhysics() const override {return mpPhysics;}
	INetwork *GetNetwork() const override {return mpNetwork;}
	
	void Stop() override;
	
	//void SendCmd(const char *asText) override;
private:
	IEngineCore *mpCore{nullptr};

	ICommandLine *mpCommandLine{nullptr};
	IMemoryManager *mpMemoryManager{nullptr};
	ILogger *mpLogger{nullptr};
	IConfig *mpConfig{nullptr};
	
	ICvarRegistry *mpCvarRegistry{nullptr};
	ICmdRegistry *mpCmdRegistry{nullptr};
	
	ICmdProcessor *mpCmdProcessor{nullptr};
	
	IPhysics *mpPhysics{nullptr};
	INetwork *mpNetwork{nullptr};
};