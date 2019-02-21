/// @file

#include "CommonTypes.hpp"
#include "Game.hpp"

C_EXPORT IGame *GetGame(int anVersion)
{
	if(anVersion == IGame::Version)
	{
		static CGame Game;
		return &Game;
	};
	
	return nullptr;
};