/// @file

#pragma once

//#include "network/INetClient.hpp"

class CNetClient final //: public INetClient
{
public:
	CNetClient();
	~CNetClient();
	
	bool Connect(const char *asAdr, int anPort); //override;
	//void Disconnect(const char *reason, ...) override;
	
	bool SendConnectionless(const char *asAdr, int anPort, const char *asMsg); //override;
	
	bool IsConnected() const /*override*/ {return mbConnected;}
	
	//INetAdr *GetNetAdr() const override {return mpAdr;}
private:
	//INetAdr *mpAdr{nullptr};
	
	int mnSock{0};
	
	bool mbConnected{false};
};