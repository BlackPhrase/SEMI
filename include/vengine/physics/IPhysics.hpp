/// @file
/// @brief physics interface

#pragma once

struct IPhysicsWorld;

struct IPhysics
{
	/// Interface version
	static constexpr auto Version{1};
	
	/// Allocates a new physics world and returns a pointer to it
	/// @return pointer to a newly created world
	virtual IPhysicsWorld *CreateWorld() = 0;
	
	/// Destroys a world
	//virtual void DestroyWorld(IPhysicsWorld *apWorld) = 0;
};

using pfnGetPhysics = IPhysics *(*)(int anVersion);