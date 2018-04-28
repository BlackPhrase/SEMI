/// @file
/// @brief physics body interface

#pragma once

struct IPhysicsBody
{
	///
	//virtual void SetGravity(const Vec3 &avGravity) = 0;
	
	///
	//virtual const Vec3 &GetGravity() const = 0;
	
	///
	virtual void SetMass(float afMass) = 0;
	
	///
	virtual float GetMass() const = 0;
	
	///
	virtual void ApplyForce(const Vec3 &avForce) = 0;
};