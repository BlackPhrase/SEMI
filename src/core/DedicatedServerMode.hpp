#pragma once

#include "IEngineExecStrategy.hpp"

struct IEngineServer;

class CDedicatedServerMode final : public IEngineExecStrategy
{
public:
	CDedicatedServerMode();
	~CDedicatedServerMode();
	
	void Init(IEngineCore *apCore) override;
	void Shutdown() override;
	
	void Frame() override;
private:
	IEngineServer *mpEngServer{nullptr};
};