/// @file

#pragma once

#include "physics/IPhysicsWorld.hpp"

class btDiscreteDynamicsWorld;

class CPhysicsWorldBullet final : public IPhysicsWorld
{
public:
	CPhysicsWorldBullet();
	~CPhysicsWorldBullet();
	
	void Update(float afTimeStep) override;
	
	void SetGravity(const Vec3 &avGravity) override;
	const Vec3 &GetGravity() const override;
private:
	btDiscreteDynamicsWorld *mpWorld{nullptr};
};