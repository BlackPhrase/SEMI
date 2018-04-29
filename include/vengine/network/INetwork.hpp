/// @file
/// @brief network interface

#pragma once

struct INetwork
{
	/// Interface version
	static constexpr auto Version{1};
	
	/// Initialize the network system
	virtual bool Init() = 0;
	
	/// Shutdown the network system
	virtual void Shutdown() = 0;
};

using pfnGetNetwork = INetwork *(*)(int version);