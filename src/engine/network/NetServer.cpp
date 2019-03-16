/// @file

#include <cstdio>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet.h>
#endif

#include "NetServer.hpp"
#include "IClient.hpp"

CNetServer::CNetServer(int anPort)
{
	svsock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // AF_INET6
	
	//if(svsock == nInvalidSocket)
		//return false;
	
#ifdef _WIN32
	unsigned long mode{1};
	ioctlsocket(svsock, FIONBIO, &mode);
#endif
	
	static sockaddr_in svadr{};
	//static sockaddr_in6 svadr{};
	memset(&svadr, 0, sizeof(svadr));
	
	svadr.sin_family = AF_INET;
	svadr.sin_port = htons(anPort);
	svadr.sin_addr.s_addr = htonl(INADDR_ANY);
	/*
	svadr.sin6_family = AF_INET6;
	svadr.sin6_port = htons(anPort);
	svadr.sin6_addr.s_addr = htonl(INADDR_ANY);
	*/
	
	if(bind(svsock, (sockaddr*)&svadr, sizeof(svadr)) == -1)
	{
		printf("CNetwork::StartServer: Binding failed! %d (%d, %p, %d)\n", WSAGetLastError(), svsock, (sockaddr*)&svadr, sizeof(svadr));
		//return false;
	};
	
	//if(listen(svsock, 10) == -1)
		//return false;
};

CNetServer::~CNetServer()
{
	//shutdown(svsock, SHUT_RDWR); // TODO
	
#ifdef _WIN32
	closesocket(svsock);
#else
	close(svsock);
#endif
};

void CNetServer::Receive()
{
	char sMsg[256]{};
	int nRetVal{recv(svsock, sMsg, sizeof(sMsg), 0)};
	
	if(nRetVal < 0)
	{
		//if(WSAGetLastError() == WSAEWOULDBLOCK)
			//return;
	};
	
	if(HandleConnectionless())
		return;
	
	printf("[Server] Got: %s from someone\n", sMsg);
};

void CNetServer::BroadcastMsg(INetMsg *apMsg)
{
	for(auto It : mvClients)
		if(It->IsConnected())
			It->SendMsg(apMsg);
};

void CNetServer::AddConnectionlessMsgHandler(IConnectionlessMsgHandler *apHandler)
{
	if(!apHandler)
		return;
	
	mvConnectionlessMsgHandlers.push_back(apHandler);
};

int CNetServer::FindFreeSlot() const
{
	// TODO
	return 0;
};

bool CNetServer::HandleConnectionless()
{
	// TODO
	return false;
};

bool CNetServer::SendConnectionless(const char *asAdr, int anPort, const char *asMsg)
{
	// TODO
	return false;
};

void CNetServer::SendSequencedPacket(const char *asAdr, int anPort, int anSeqNum, int anServerLastAck, const void *apData)
{
	// TODO
};

void CNetServer::ReceiveSequencedPacket(const char *asAdr, int anPort, int *anSeqNum, int *anClientLastAck, void *apData)
{
	// TODO
};