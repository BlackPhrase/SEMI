/// @file

#include <cstdio>
#include <unistd.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2ipdef.h>
#else
#include <sys/socket.h>
#include <netinet.h>
#endif

#include "Network.hpp"

#ifdef _WIN32
WSAData gWinSockData{};
#endif

constexpr auto nInvalidSocket{-1};

// TODO: IPv6 support

CNetwork::CNetwork() = default;
CNetwork::~CNetwork() = default;

bool CNetwork::Init()
{
	printf("CNetwork::Init\n");
	
#ifdef _WIN32
	int nResult{WSAStartup(MAKEWORD(2, 2), &gWinSockData)};
	
	if(nResult != 0)
	{
		printf("WinSock startup failed: %d\n", nResult);
		return false;
	};
#endif
	
	if(!StartServer(nServerPort))
		return false;
	
	if(!StartClient())
		return false;
	
	if(!ConnectClient("127.0.0.1", nServerPort))
		return false;
	
	return true;
};

void CNetwork::Shutdown()
{
	//shutdown(svsock, SHUT_RDWR); // TODO
	
#ifdef _WIN32
	closesocket(svsock);
#else
	close(svsock);
#endif

	mbServerStarted = false;
	
	//shutdown(clsock, SHUT_RDWR); // TODO
	
#ifdef _WIN32
	closesocket(clsock);
#else
	close(clsock);
#endif

	mbClientStarted = false;
	
#ifdef _WIN32
	WSACleanup();
#endif
};

void CNetwork::Update()
{
	if(mbServerStarted)
	{
		char sMsg[256]{};
		int nRetVal{recv(svsock, sMsg, sizeof(sMsg), 0)};
		
		if(nRetVal < 0)
		{
			//if(WSAGetLastError() == WSAEWOULDBLOCK)
				//return;
		};
		
		printf("[Server] Got: %s\n", sMsg);
	};
	
	if(mbClientStarted)
	{
		ClientSend("127.0.0.1", nServerPort, "Hello World!");
	};
};

bool CNetwork::StartServer(int anPort)
{
	svsock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // AF_INET6
	
	if(svsock == nInvalidSocket)
		return false;
	
	unsigned long mode{1};
	ioctlsocket(svsock, FIONBIO, &mode);
	
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
		return false;
	};
	
	//if(listen(svsock, 10) == -1)
		//return false;
	
	mbServerStarted = true;
	printf("Server started! (port: %d)\n", anPort);
	return true;
};

bool CNetwork::StartClient()
{
	clsock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // AF_INET6
	
	if(clsock == nInvalidSocket)
		return false;
	
	//if(bind(clsock, (sockaddr*)&cladr, sizeof(sockaddr)) == -1)
		//return false;
	
	mbClientStarted = true;
	printf("Client started!\n");
	return true;
};

bool CNetwork::ConnectClient(const char *asAdr, int anPort = nServerPort)
{
	if(!mbClientStarted)
		return false;
	
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
	
	//if(connect(clsock, (sockaddr*)&remoteadr, sizeof(remoteadr)) == -1)
		//return false;
	
	//printf("Client connected! (adr: %s, port: %n)\n", asAdr, anPort);
	return true;
};

bool CNetwork::ClientSend(const char *asAdr, int anPort, const char *asMsg)
{
	if(!mbClientStarted)
		return false;
	
	char sMsg[256]{};
	sprintf(sMsg, "%s", asMsg);
	
	static sockaddr_in remoteadr{};
	//static sockaddr_in6 remoteadr{};
	memset(&remoteadr, 0, sizeof(remoteadr));
	
	remoteadr.sin_family = AF_INET; // AF_INET6
	remoteadr.sin_addr.s_addr = inet_addr(asAdr);
	remoteadr.sin_port = htons(anPort);
	
	int nBytesSent = sendto(clsock, sMsg, sizeof(sMsg), 0, (sockaddr*)&remoteadr, sizeof(remoteadr));
	
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