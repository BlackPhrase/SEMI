/// @file

#pragma once

#include <memory>

#include "network/INetwork.hpp"

struct INetworkImpl;
class CNetServer;
class CNetClient;

class CNetwork final : public INetwork
{
public:
	CNetwork(INetworkImpl *apImpl);
	~CNetwork();
	
	bool Init() override;
	void Shutdown() override;
	
	void Update() override;
	
	bool StartServer(int anPort = nServerPort) override;
	bool StartClient() override;
	
	bool ClientSendConnectionless(const char *asAdr, int anPort, const char *asMsg) override;
private:
	bool ConnectClient(const char *asAdr, int anPort = nServerPort);
	
	std::unique_ptr<CNetServer> mpServer;
	std::unique_ptr<CNetClient> mpClient;
	
	INetworkImpl *mpImpl{nullptr};
	
	bool mbInitialized{false};
	bool mbServerStarted{false};
	bool mbClientStarted{false};
};