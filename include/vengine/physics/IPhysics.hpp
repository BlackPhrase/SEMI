/// @file
/// @brief physics interface

#pragma once

struct IPhysicsWorld;

struct IPhysics
{
	///
	virtual IPhysicsWorld *CreateWorld() = 0;
};

using pfnGetPhysics = IPhysics *(*)();