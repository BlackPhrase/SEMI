/// @file

#pragma once

#include <vector>
#include <list>

#include "network/INetServer.hpp"

struct IClient;
using tClientVec = std::vector<IClient*>;

using tConnectionlessMsgHandlerList = std::list<IConnectionlessMsgHandler*>;

class CNetServer final : public INetServer
{
public:
	CNetServer(int anPort);
	~CNetServer();
	
	void Receive();
	
	IClient *GetClientByID(int index) const {return mvClients.at(index);}
	
	//IClient *GetClient(int id) const override;
	//INetClient *GetClient(int id) const override;
	
	void BroadcastMsg(INetMsg *apMsg) override;
	
	bool SendConnectionless(const char *asAdr, int anPort, const char *asMsg) override;
	
	void SendSequencedPacket(const char *asAdr, int anPort, int anSeqNum, int anServerLastAck, const void *apData) override;
	void ReceiveSequencedPacket(const char *asAdr, int anPort, int *anSeqNum, int *anClientLastAck, void *apData) override;
	
	//INetChannel *GetNetChannel() const override;
	
	int GetClientCount() const override {return mvClients.size();}
	
	int GetMaxClients() const override {return 1;} // TODO: support 1 client only for now (singleplayer)
	
	void AddConnectionlessMsgHandler(IConnectionlessMsgHandler *apHandler) override;
private:
	int FindFreeSlot() const;
	bool HandleConnectionless();
	
	tClientVec mvClients;
	tConnectionlessMsgHandlerList mvConnectionlessMsgHandlers;
	
	int svsock{0};
};