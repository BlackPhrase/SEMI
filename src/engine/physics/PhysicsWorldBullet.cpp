/// @file

#include "PhysicsWorldBullet.hpp"

CPhysicsWorldBullet::CPhysicsWorldBullet() //= default;
{
	btDefaultCollisionConfiguration *pCollisionConfig = new btDefaultCollisionConfiguration(); // TODO: delete
	
	btCollisionDispatcher *pCollisionDispatcher = new btCollisionDispatcher(pCollisionConfig); // TODO: delete
	
	btBroadphaseInterface *pOverlappingPairCache = new btDbvtBroadphase(); // TODO: delete
	
	btSequentialImpulseConstraintSolver *pSolver = new btSequentialImpulseConstraintSolver(); // TODO: delete
	
	mpWorld = new btDiscreteDynamicsWorld(pCollisionDispatcher, pOverlappingPairCache, pSolver, pCollisionConfig); // TODO: delete
};

CPhysicsWorldBullet::~CPhysicsWorldBullet() = default;

void CPhysicsWorldBullet::Update(float afTimeStep)
{
	mpWorld->stepSimulation(afTimeStep);
};

void CPhysicsWorldBullet::SetGravity(const Vec3 &avGravity)
{
	mpWorld->setGravity(btVector(avGravity.x, avGravity.y, avGravity.z));
};

const Vec3 &CPhysicsWorldBullet::GetGravity() const
{
	return mpWorld->getGravity(); // TODO
};