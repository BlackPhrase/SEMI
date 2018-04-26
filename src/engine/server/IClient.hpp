/// @file
/// @brief connected client interface

#pragma once

struct IClient
{
	/// Disconnect the client with a reason
	virtual void Disconnect(const char *reason, ...) = 0;
};