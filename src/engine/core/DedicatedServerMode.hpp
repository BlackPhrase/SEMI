/// @file

#pragma once

#include "IEngineExecMode.hpp"

struct IEngineServer;

class CDedicatedServerMode final : public IEngineExecMode
{
public:
	CDedicatedServerMode();
	~CDedicatedServerMode();
	
	void Init(ICoreEnv *apCoreEnv) override;
	void Shutdown() override;
	
	void Frame(float afTimeStep) override;
private:
	IEngineServer *mpEngServer{nullptr};
};