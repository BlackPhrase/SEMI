/// @file

#include <cstdio>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet.h>
#endif

#include "NetClient.hpp"
#include "NetworkTypes.hpp"

CNetClient::CNetClient()
{
	mnSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // AF_INET6
	
	//if(mnSock == nInvalidSocket) // TODO
		//return false;
	
	//if(bind(mnSock, (sockaddr*)&cladr, sizeof(sockaddr)) == -1)
		//return false;
};

CNetClient::~CNetClient()
{
	//shutdown(mnSock, SHUT_RDWR); // TODO
	
#ifdef _WIN32
	closesocket(mnSock);
#else
	close(mnSock);
#endif
};

bool CNetClient::Connect(const char *asAdr, int anPort)
{
	static sockaddr_in remoteadr{};
	//static sockaddr_in6 remoteadr{};
	memset(&remoteadr, 0, sizeof(remoteadr));
	
	remoteadr.sin_family = AF_INET; // AF_INET6
	remoteadr.sin_addr.s_addr = inet_addr(asAdr);
	remoteadr.sin_port = htons(anPort);
	/*
	remoteadr.sin6_family = AF_INET6;
	remoteadr.sin6_addr.s_addr = inet_addr(asAdr);
	remoteadr.sin6_port = htons(anPort);
	*/
	//static res = inet_pton(AF_INET6, asAdr, &remoteadr.sin6_addr);
	
	//if(connect(mnSocl, (sockaddr*)&remoteadr, sizeof(remoteadr)) == -1)
		//return false;
	
	//printf("Client connected! (adr: %s, port: %n)\n", asAdr, anPort);
	return true;
};

void CNetClient::Disconnect(const char *reason, ...)
{
};

bool CNetClient::SendConnectionless(const char *asAdr, int anPort, const char *asMsg)
{
	char sMsg[256]{};
	sprintf(sMsg, "%s", asMsg);
	
	static sockaddr_in remoteadr{};
	//static sockaddr_in6 remoteadr{};
	memset(&remoteadr, 0, sizeof(remoteadr));
	
	remoteadr.sin_family = AF_INET; // AF_INET6
	remoteadr.sin_addr.s_addr = inet_addr(asAdr);
	remoteadr.sin_port = htons(anPort);
	
	int nBytesSent = sendto(mnSock, sMsg, sizeof(sMsg), 0, (sockaddr*)&remoteadr, sizeof(remoteadr));
	
	if(nBytesSent < 0)
	{
#ifdef _WIN32
		printf("Error sending packet: %d\n", WSAGetLastError());
#else
		printf("Error sending packet: %s\n", strerror(errno));
#endif
		return false;
	};
	
	sprintf(sMsg, "[Cl->Sv] %s", asMsg);
	printf("%s\n", sMsg);
	return true;
};

void CNetClient::SendSequencedPacket(const char *asAdr, int anPort, int anSeqNum, int anClientLastAck, const void *apData)
{
	// TODO
};

void CNetClient::ReceiveSequencedPacket(const char *asAdr, int anPort, int *anSeqNum, int *anServerLastAck, void *apData)
{
	// TODO
};