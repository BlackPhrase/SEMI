/// @file

#include "CommonTypes.hpp"
#include "Network.hpp"

C_EXPORT INetwork *GetNetwork(int version)
{
	if(version == INetwork::Version)
	{
		static CNetwork Network;
		return &Network;
	};
};