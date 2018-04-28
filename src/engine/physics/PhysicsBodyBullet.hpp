/// @file

#pragma once

#include "physics/IPhysicsBody.hpp"

class btRigidBody;

class CPhysicsBody final : public IPhysicsBody
{
public:
	CPhysicsBody();
	~CPhysicsBody();
	
	void SetMass(float afMass) override;
	float GetMass() const override;
	
	void ApplyForce(const Vec3 &avForce) override;
private:
	btRigidBody *mpBody{nullptr};
};