/// @file
/// @brief network server interface

#pragma once

struct IClient;
struct INetMsg;
struct INetChannel;
struct IConnectionlessMsgHandler;

struct INetServer
{
	/// @return pointer to a client
	//virtual IClient *GetClient(int id) const = 0;
	//virtual INetClient *GetClient(int id) const = 0;
	
	/// Broadcast the message to each connected client
	virtual void BroadcastMsg(INetMsg *apMsg) = 0;
	
	///
	virtual bool SendConnectionless(const char *asAdr, int anPort, const char *asMsg) = 0;
	
	///
	virtual void SendSequencedPacket(const char *asAdr, int anPort, int anSeqNum, int anServerLastAck, const void *apData) = 0;
	
	///
	virtual void ReceiveSequencedPacket(const char *asAdr, int anPort, int *anSeqNum, int *anClientLastAck, void *apData) = 0;
	
	/// @return pointer to the network channel
	//virtual INetChannel *GetNetChannel() const = 0;
	
	///
	virtual int GetClientCount() const = 0;
	
	///
	virtual int GetMaxClients() const = 0;
	
	///
	virtual void AddConnectionlessMsgHandler(IConnectionlessMsgHandler *apHandler) = 0;
};