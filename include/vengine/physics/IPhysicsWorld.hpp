/// @file
/// @brief physics world interface

#pragma once

struct IPhysicsBody;

struct IPhysicsWorld
{
	/// Simulate the worls
	virtual void Update(float afTimeStep) = 0;
	
	/// Set a new gravity value for the world
	virtual void SetGravity(const Vec3 &avGravity) = 0;
	
	/// @return current world's gravity
	virtual const Vec3 &GetGravity() const = 0;
	
	/// Create a new body
	virtual IPhysicsBody *CreateBody() = 0;
	
	/// Destroy the body
	virtual void DestroyBody(IPhysicsBody *apBody) = 0;
};