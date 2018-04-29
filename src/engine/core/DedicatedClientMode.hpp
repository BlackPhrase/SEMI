/// @file

#pragma once

#include "IEngineExecMode.hpp"

struct IEngineClient;

class CDedicatedClientMode final : public IEngineExecMode
{
public:
	CDedicatedClientMode();
	~CDedicatedClientMode();
	
	void Init(ICoreEnv *apCoreEnv) override;
	void Shutdown() override;
	
	void Frame(float afTimeStep) override;
private:
	IEngineClient *mpEngClient{nullptr};
};