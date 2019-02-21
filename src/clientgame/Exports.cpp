/// @file

#include "CommonTypes.hpp"
#include "ClientGame.hpp"

C_EXPORT IClientGame *GetClientGame(int anVersion)
{
	if(anVersion == IClientGame::Version)
	{
		static CClientGame ClientGame;
		return &ClientGame;
	};
	
	return nullptr;
};