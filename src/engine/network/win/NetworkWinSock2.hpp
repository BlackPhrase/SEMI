/// @file

#include <winsock2.h>

#include "INetworkImpl.hpp"

class CNetworkWinSock2 final : public INetworkImpl
{
public:
	CNetworkWinSock2();
	~CNetworkWinSock2();
	
	bool Init() override;
	void Shutdown() override;
private:
	WSAData mWinSockData{};
};