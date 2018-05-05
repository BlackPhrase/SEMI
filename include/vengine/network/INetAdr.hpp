/// @file
/// @brief network address interface

#pragma once

struct INetAdr
{
	/// @return true if this net address is local
	virtual bool IsLocal() const = 0;
	
	enum class Type : int
	{
		Temp
		// TODO
	};
	
	/// @return Type of the network address
	virtual Type GetType() const = 0;
};