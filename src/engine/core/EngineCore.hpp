/// @file

#pragma once

#include <memory>

#include "core/IEngineCore.hpp"

struct IEngineExecMode;
struct INetwork;
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
	bool InitPhysics();
	bool InitNetworking();
	
	std::unique_ptr<IEngineExecMode> mpExecMode;
	//std::unique_ptr<CTimer> mpTimer;
	
	IPhysics *mpPhysics{nullptr};
	INetwork *mpNetwork{nullptr};
	
	bool mbShouldStop{false};
};