/// @file

#include "vengine/CommonTypes.hpp"
#include "Physics.hpp"

C_EXPORT IPhysics *GetPhysics(int version)
{
	if(version == IPhysics::Version)
	{
		static CPhysics Physics;
		return &Physics;
	};
	
	return nullptr;
};