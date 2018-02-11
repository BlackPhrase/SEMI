#pragma once

#include "IEngineExecMode.hpp"

class CDedicatedServerMode;
class CDedicatedClientMode;

class CListenServerMode final : public IEngineExecMode
{
public:
	//CListenServerMode(std::unique_ptr<CDedicatedServerMode> apDedicatedServer,
	//				  std::unique_ptr<CDedicatedClientMode> apDedicatedClient);
	CListenServerMode(CDedicatedServerMode *apDedicatedServer, CDedicatedClientMode *apDedicatedClient)
		: mpDedicatedServer(apDedicatedServer), mpDedicatedClient(apDedicatedClient){}
	~CListenServerMode();
	
	void Init(IEngineCore *apCore) override;
	void Shutdown() override;
	
	void Frame(float afTimeStep) override;
private:
	CDedicatedServerMode *mpDedicatedServer{nullptr};
	CDedicatedClientMode *mpDedicatedClient{nullptr};
};