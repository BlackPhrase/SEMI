/// @file

#include "CommonTypes.hpp"
#include "Network.hpp"

#ifdef _WIN32
#include "win/NetworkWinSock2.hpp"
#endif

C_EXPORT INetwork *GetNetwork(int version)
{
	if(version == INetwork::Version)
	{
#ifdef _WIN32
		static CNetworkWinSock2 NetworkImpl;
#else
		// TODO
#endif

		static CNetwork Network(&NetworkImpl);
		return &Network;
	};
};