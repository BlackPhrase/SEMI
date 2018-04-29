/// @file

#include "CommonTypes.hpp"
#include "EngineClient.hpp"

C_EXPORT IEngineClient *GetEngineClient(int version)
{
	if(version == IEngineClient::Version)
	{
		static CEngineClient EngClient;
		return &EngClient;
	};
};