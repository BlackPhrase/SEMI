/// @file

#include "CoreEnv.hpp"
#include "core/IEngineCore.hpp"

CCoreEnv::CCoreEnv(IEngineCore *apCore, ICommandLine *apCommandLine, IMemoryManager *apMemoryManager, ILogger *apLogger, IConfig *apConfig,
					ICvarRegistry *apCvarRegistry, ICmdRegistry *apCmdRegistry, ICmdProcessor *apCmdProcessor, IPhysics *apPhysics, INetwork *apNetwork)
	: mpCore(apCore), mpCommandLine(apCommandLine), mpMemoryManager(apMemoryManager), mpLogger(apLogger), mpConfig(apConfig),
	mpCvarRegistry(apCvarRegistry), mpCmdRegistry(apCmdRegistry), mpCmdProcessor(apCmdProcessor), mpPhysics(apPhysics), mpNetwork(apNetwork){}

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