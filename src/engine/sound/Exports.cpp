/// @file

#include "CommonTypes.hpp"
#include "Sound.hpp"

C_EXPORT ISound *GetSound(int anVersion, const ICoreEnv &apCoreEnv)
{
	if(anVersion == ISound::Version)
	{
		static CSound Sound(apCoreEnv);
		return &Sound;
	};
	
	return nullptr;
};