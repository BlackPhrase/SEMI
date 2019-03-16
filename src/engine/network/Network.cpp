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

CNetwork::CNetwork(const ICoreEnv &apCoreEnv, INetworkImpl *apImpl) : mpCoreEnv(apCoreEnv), mpImpl(apImpl){}

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

INetServer *CNetwork::StartServer(const ServerStartSettings &apSettings)
{
	if(mbServerStarted)
		return mpServer.get();
	
	//if(!mbServer)
		mpServer = std::make_unique<CNetServer>(apSettings.mnPort);
	
	mbServerStarted = true;
	printf("Server started! (port: %d)\n", apSettings.mnPort);
	return mpServer.get();
};

INetClient *CNetwork::StartClient()
{
	if(mpClient)
		return mpClient.get();
	
	//if(!mpClient)
		mpClient = std::make_unique<CNetClient>();
	
	printf("Client started!\n");
	return mpClient.get();
};

bool CNetwork::ConnectClient(const char *asAdr, int anPort)
{
	if(!mpClient)
		return false;
	
	return mpClient->Connect(asAdr, anPort);
};