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
	CNetwork(const ICoreEnv &apCoreEnv, INetworkImpl *apImpl);
	~CNetwork();
	
	bool Init() override;
	void Shutdown() override;
	
	void Update() override;
	
	INetServer *StartServer(const ServerStartSettings &apSettings) override;
	INetClient *StartClient() override;
private:
	bool ConnectClient(const char *asAdr, int anPort = nDefaultServerPort);
	
	std::unique_ptr<CNetServer> mpServer;
	std::unique_ptr<CNetClient> mpClient;
	
	const ICoreEnv &mpCoreEnv;
	
	INetworkImpl *mpImpl{nullptr};
	
	bool mbInitialized{false};
	bool mbServerStarted{false};
};