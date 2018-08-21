/// @file

#include <cstdio>
//#include <unistd.h>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet.h>
#endif

#include "Network.hpp"
#include "INetworkImpl.hpp"
#include "NetServer.hpp"
#include "NetClient.hpp"

// TODO: IPv6 support

CNetwork::CNetwork(INetworkImpl *apImpl) : mpImpl(apImpl){}

CNetwork::~CNetwork() = default;

bool CNetwork::Init()
{
	if(mbInitialized)
		return true; // TODO: false?
	
	printf("CNetwork::Init\n");
	
	if(!mpImpl->Init())
		return false;
	
	//if(!ConnectClient("127.0.0.1", nServerPort))
		//return false;
	
	mbInitialized = true;
	return true;
};

void CNetwork::Shutdown()
{
	if(!mbInitialized)
		return;

	if(mpServer)
		mpServer.release();
	
	mbServerStarted = false;
	
	if(mpClient)
		mpClient.release();
	
	mbClientStarted = false;
	
	mpImpl->Shutdown();
};

void CNetwork::Update()
{
	if(!mbInitialized)
		return;
	
	if(mbServerStarted)
		if(mpServer)
			mpServer->Receive();
};

bool CNetwork::StartServer(int anPort)
{
	if(mbServerStarted)
		return true;
	
	//if(!mbServer)
		mpServer = std::make_unique<CNetServer>(anPort);
	
	mbServerStarted = true;
	printf("Server started! (port: %d)\n", anPort);
	return true;
};

bool CNetwork::StartClient()
{
	if(mbClientStarted)
		return true;
	
	//if(!mpClient)
		mpClient = std::make_unique<CNetClient>();
	
	mbClientStarted = true;
	printf("Client started!\n");
	return true;
};

bool CNetwork::ConnectClient(const char *asAdr, int anPort)
{
	if(!mbClientStarted)
		return false;
	
	if(!mpClient)
		return false;
	
	return mpClient->Connect(asAdr, anPort);
};

bool CNetwork::ClientSendConnectionless(const char *asAdr, int anPort, const char *asMsg)
{
	if(!mbClientStarted)
		return false;
	
	if(!mpClient)
		return false;
	
	return mpClient->SendConnectionless(asAdr, anPort, asMsg);
};