#pragma once

#include <memory>
#include "vengine/IEngineCore.hpp"

struct IEngineExecMode;
//class CTimer;

class CEngineCore final : public IEngineCore
{
public:
	CEngineCore();
	~CEngineCore();
	
	bool Init(const IEngineCore::InitParams &aInitParams) override;
	void Shutdown() override;
	
	bool Frame() override;
	
	void Stop() override;
	
	void SendCmd(const char *asText) override;
private:
	std::unique_ptr<IEngineExecMode> mpExecMode;
	//std::unique_ptr<CTimer> mpTimer;
	
	bool mbShouldStop{false};
};