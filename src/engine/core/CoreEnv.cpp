/// @file

#include "CoreEnv.hpp"
#include "core/IEngineCore.hpp"

CCoreEnv::CCoreEnv(IEngineCore *apCore, ICvarRegistry *apCvarRegistry, ICmdRegistry *apCmdRegistry, IPhysics *apPhysics, INetwork *apNetwork)
	: mpCore(apCore), mpCvarRegistry(apCvarRegistry), mpCmdRegistry(apCmdRegistry), mpPhysics(apPhysics), mpNetwork(apNetwork){}

CCoreEnv::~CCoreEnv() = default;

void CCoreEnv::Stop()
{
	mpCore->RequestClose();
};

/*
void CCoreEnv::SendCmd(const char *asText)
{
	//mpCmdProcessor->Insert(asText);
};
*/