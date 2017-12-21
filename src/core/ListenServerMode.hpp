#pragma once

#include "IEngineExecStrategy.hpp"

class CDedicatedServerMode;
class CDedicatedClientMode;

class CListenServerMode final : public IEngineExecStrategy
{
public:
	//CListenServerMode(std::unique_ptr<CDedicatedServerMode> apDedicatedServer,
	//				  std::unique_ptr<CDedicatedClientMode> apDedicatedClient);
	CListenServerMode(CDedicatedServerMode *apDedicatedServer, CDedicatedClientMode *apDedicatedClient)
		: mpDedicatedServer(apDedicatedServer), mpDedicatedClient(apDedicatedClient){}
	~CListenServerMode();
	
	void Init(IEngineCore *apCore) override;
	void Shutdown() override;
	
	void Frame() override;
private:
	CDedicatedServerMode *mpDedicatedServer{nullptr};
	CDedicatedClientMode *mpDedicatedClient{nullptr};
};