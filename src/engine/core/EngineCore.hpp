/// @file

#pragma once

#include <memory>

#include "core/IEngineCore.hpp"

struct IEngineExecMode;
struct INetwork;
struct IPhysics;
//struct IScript;
//class CTimer;
class CCoreEnv;
class CCvarRegistry;
class CCmdRegistry;
class CThreadPool;

class CEngineCore final : public IEngineCore
{
public:
	CEngineCore();
	~CEngineCore();
	
	bool Init(const IEngineCore::InitParams &aInitParams) override;
	void Shutdown() override;
	
	bool Frame() override;
	
	void RequestClose() override {mbCloseRequested = true;}
private:
	bool InitPhysics();
	bool InitNetworking();
	//bool InitScripting();
	
	std::unique_ptr<IEngineExecMode> mpExecMode;
	//std::unique_ptr<CTimer> mpTimer;
	
	CCoreEnv *mpEnv{nullptr};
	
	std::unique_ptr<CCvarRegistry> mpCvarRegistry;
	std::unique_ptr<CCmdRegistry> mpCmdRegistry;
	
	std::unique_ptr<CThreadPool> mpThreadPool;
	
	IPhysics *mpPhysics{nullptr};
	INetwork *mpNetwork{nullptr};
	//IScript *mpScript{nullptr};
	
	bool mbCloseRequested{false};
};