/// @file

#pragma once

#include "network/INetwork.hpp"

class CNetwork final : public INetwork
{
public:
	CNetwork();
	~CNetwork();
	
	bool Init() override;
	void Shutdown() override;
	
	void Update() override;
	
	bool StartServer(int anPort = nServerPort) override;
	bool StartClient() override;
	
	bool ClientSendConnectionless(const char *asAdr, int anPort, const char *asMsg) override;
private:
	bool ConnectClient(const char *asAdr, int anPort);
	
	int svsock{0};
	int clsock{0};
	
	bool mbServerStarted{false};
	bool mbClientStarted{false};
};