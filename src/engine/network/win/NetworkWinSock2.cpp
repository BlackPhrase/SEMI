/// @file

#include <cstdio>

//#include <ws2ipdef.h>

#include "NetworkWinSock2.hpp"

CNetworkWinSock2::CNetworkWinSock2() = default;
CNetworkWinSock2::~CNetworkWinSock2() = default;

bool CNetworkWinSock2::Init()
{
	int nResult{WSAStartup(MAKEWORD(2, 2), &mWinSockData)};
	
	if(nResult != 0)
	{
		printf("WinSock startup failed: %d\n", nResult);
		return false;
	};

	return true;
};

void CNetworkWinSock2::Shutdown()
{
	WSACleanup();
};