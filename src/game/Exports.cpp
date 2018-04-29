/// @file

#include "CommonTypes.hpp"
#include "Game.hpp"

C_EXPORT IGame *GetGame(int version)
{
	if(version == IGame::Version)
	{
		static CGame Game;
		return &Game;
	};
};