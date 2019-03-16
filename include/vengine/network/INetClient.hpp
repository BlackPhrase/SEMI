/// @file
/// @brief network client interface

#pragma once

struct INetMsg;
struct INetChannel;

struct INetClient
{
	/// Try to connect to a server using its IP and port
	virtual bool Connect(const char *asIP, int anPort) = 0; // INetAdr?
	//virtual bool Connect(const char *hostname) = 0;
	
	/// Disconnect from the server
	virtual void Disconnect(const char *asReason, ...) = 0;
	
	/// @return true if the client is connected to some server
	virtual bool IsConnected() const = 0;
	
	///
	virtual bool SendConnectionless(const char *asAdr, int anPort, const char *asMsg) = 0;
	
	///
	virtual void SendSequencedPacket(const char *asAdr, int anPort, int anSeqNum, int anServerLastAck, const void *apData) = 0;
	
	///
	virtual void ReceiveSequencedPacket(const char *asAdr, int anPort, int *anSeqNum, int *anClientLastAck, void *apData) = 0;
	
	/// Send a message to a server if connected
	//virtual void SendMsg(INetMsg *apMsg) = 0;
	
	///
	//virtual INetChannel *GetNetChannel() const = 0;
	
	///
	//virtual IServerInfo *GetServerInfo() const = 0;
};