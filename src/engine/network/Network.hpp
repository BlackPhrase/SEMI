/// @file

#pragma once

#include "network/INetwork.hpp"

constexpr auto nServerPort{308};

class CNetwork final : public INetwork
{
public:
	CNetwork();
	~CNetwork();
	
	bool Init() override;
	void Shutdown() override;
	
	void Update() override;
private:
	bool StartServer(int anPort = nServerPort);
	bool StartClient();
	
	bool ConnectClient(const char *asAdr, int anPort);
	
	bool ClientSend(const char *asAdr, int anPort, const char *asMsg);
	
	int svsock{0};
	int clsock{0};
	
	bool mbServerStarted{false};
	bool mbClientStarted{false};
};