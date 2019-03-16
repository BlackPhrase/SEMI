/// @file
/// @brief network interface

#pragma once

constexpr auto nDefaultServerPort{308};
constexpr auto nDefaultServerClientCount{1};

struct ICoreEnv;
struct INetClient;
struct INetServer;

struct INetwork
{
	/// Interface version
	static constexpr auto Version{1};
	
	/// Initialize the network system
	virtual bool Init() = 0;
	
	/// Shutdown the network system
	virtual void Shutdown() = 0;
	
	///
	virtual void Update() = 0;
	
	struct ServerStartSettings
	{
		int mnPort{nDefaultServerPort};
		int mnMaxClients{nDefaultServerClientCount};
	};
	
	///
	virtual INetServer *StartServer(const ServerStartSettings &apSettings /*= ServerStartSettings()*/) = 0;
	
	///
	virtual INetClient *StartClient() = 0;
};

using pfnGetNetwork = INetwork *(*)(int anVersion, const ICoreEnv &apCoreEnv);