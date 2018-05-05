/// @file
/// @brief network server interface

#pragma once

struct IClient;
struct INetMsg;
struct INetChannel;

struct INetServer
{
	/// @return pointer to a client
	virtual IClient *GetClient(int id) const = 0;
	//virtual INetClient *GetClient(int id) const = 0;
	
	/// Broadcast the message to each connected client
	virtual void BroadcastMsg(INetMsg *apMsg) = 0;
	
	/// @return pointer to the network channel
	virtual INetChannel *GetNetChannel() const = 0;
	
	///
	virtual int GetClientCount() const = 0;
	
	///
	virtual int GetMaxClients() const = 0;
};