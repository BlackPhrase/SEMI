/// @file

#include "CommonTypes.hpp"
#include "EngineServer.hpp"

C_EXPORT IEngineServer *GetEngineServer(int version)
{
	if(version == IEngineServer::Version)
	{
		static CEngineServer EngServer;
		return &EngServer;
	};
};