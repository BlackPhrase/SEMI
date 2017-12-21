#pragma once

#include "IEngineExecStrategy.hpp"

struct IEngineClient;

class CDedicatedClientMode final : public IEngineExecStrategy
{
public:
	CDedicatedClientMode();
	~CDedicatedClientMode();
	
	void Init(IEngineCore *apCore) override;
	void Shutdown() override;
	
	void Frame() override;
private:
	IEngineClient *mpEngClient{nullptr};
};