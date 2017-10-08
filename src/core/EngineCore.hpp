#pragma once

#include "vengine/IEngineCore.hpp"

struct IEngineExecStrategy;

class CEngineCore final : public IEngineCore
{
public:
	CEngineCore(const InitParams &aInitParams);
	~CEngineCore();
	
	void Init() override;
	void Shutdown() override;
	
	void Frame() override;
	
	void Stop() override;
	
	void SendCmd(const char *asText) override;
private:
	IEngineExecStrategy *mpExecMode{nullptr};
	
	bool mbShouldStop{false};
};