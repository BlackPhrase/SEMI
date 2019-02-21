/// @file
/// @brief network interface

#pragma once

constexpr auto nServerPort{308};

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
	
	///
	//virtual INetServer *StartServer() = 0; // TODO
	virtual bool StartServer(int anPort = nServerPort) = 0;
	
	///
	//virtual INetClient *StartClient() = 0; // TODO
	virtual bool StartClient() = 0;
	
	///
	virtual bool ClientSendConnectionless(const char *asAdr, int anPort, const char *asMsg) = 0;
};

using pfnGetNetwork = INetwork *(*)(int anVersion, const ICoreEnv &apCoreEnv);