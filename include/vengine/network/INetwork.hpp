/// @file
/// @brief network interface

#pragma once

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
	//virtual INetClient *StartClient() = 0; // TODO
	
	///
	//virtual INetServer *StartServer() = 0; // TODO
};

using pfnGetNetwork = INetwork *(*)(int anVersion);