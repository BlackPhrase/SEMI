#include "vengine/CommonTypes.hpp"
#include "EngineCore.hpp"

C_EXPORT IEngineCore *GetEngineCore(int version)
{
	if(version == IEngineCore::Version)
	{
		static CEngineCore Engine;
		return &Engine;
	};
};