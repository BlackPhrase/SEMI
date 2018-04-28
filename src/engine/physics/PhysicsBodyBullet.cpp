/// @file

#include <btRigidBody.h>

#include "PhysicsBodyBullet.hpp"

CPhysicsBodyBullet::CPhysicsBodyBullet() = default;
CPhysicsBodyBullet::~CPhysicsBodyBullet() = default;

void CPhysicsBodyBullet::SetMass(float afMass)
{
	mpBody->setMassProps(afMass, mpBody->getLocalInertia());
};

float CPhysicsBodyBullet::GetMass() const
{
	return -mpBody->getInvMass();
};

void CPhysicsBodyBullet::ApplyForce(const Vec3 &avForce)
{
	mpBody->applyForce(avForce);
};