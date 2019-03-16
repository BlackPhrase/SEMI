/// @file

#pragma once

#include "network/INetClient.hpp"

class CNetClient final : public INetClient
{
public:
	CNetClient();
	~CNetClient();
	
	bool Connect(const char *asAdr, int anPort) override;
	void Disconnect(const char *asReason, ...) override;
	
	bool SendConnectionless(const char *asAdr, int anPort, const char *asMsg) override;
	
	void SendSequencedPacket(const char *asAdr, int anPort, int anSeqNum, int anServerLastAck, const void *apData) override;
	void ReceiveSequencedPacket(const char *asAdr, int anPort, int *anSeqNum, int *anClientLastAck, void *apData) override;

	bool IsConnected() const override {return mbConnected;}
	
	//INetChannel *GetChannel() const override {return mpChannel;}
private:
	//INetAdr *mpAdr{nullptr};
	INetChannel *mpChannel{nullptr};
	
	int mnSock{0};
	
	bool mbConnected{false};
};