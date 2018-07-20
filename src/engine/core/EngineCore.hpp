/// @file

#pragma once

#include <memory>

#include "core/IEngineCore.hpp"

struct IEngineExecMode;
struct INetwork;
struct IPhysics;
struct IScript;
//class CTimer;
class CCoreEnv;
class CMemoryManager;
class CLogger;
class CConfig;
class CCvarRegistry;
class CCmdRegistry;
class CCmdProcessor;
class CThreadPool;

class CLogSinkInternal;

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
	bool InitScripting();
	
	std::unique_ptr<IEngineExecMode> mpExecMode;
	//std::unique_ptr<CTimer> mpTimer;
	
	std::unique_ptr<CCoreEnv> mpEnv;
	
	std::unique_ptr<CMemoryManager> mpMemoryManager;
	std::unique_ptr<CLogger> mpLogger;
	std::unique_ptr<CConfig> mpConfig;
	
	std::unique_ptr<CCvarRegistry> mpCvarRegistry;
	std::unique_ptr<CCmdRegistry> mpCmdRegistry;
	
	std::unique_ptr<CCmdProcessor> mpCmdProcessor;
	
	std::unique_ptr<CThreadPool> mpThreadPool;
	
	std::unique_ptr<CLogSinkInternal> mpLogSinkInternal;
	
	IPhysics *mpPhysics{nullptr};
	INetwork *mpNetwork{nullptr};
	IScript *mpScript{nullptr};
	
	bool mbCloseRequested{false};
};