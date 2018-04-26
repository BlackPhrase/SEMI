/// @file
/// @brief network interface

#pragma once

struct INetwork
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	virtual void Init() = 0;
	
	///
	virtual void Shutdown() = 0;
};

using pfnGetNetwork = INetwork *(*)(int version);