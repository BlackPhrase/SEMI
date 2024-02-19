/// @file

#pragma once

#include <memory>

#include <server/IEngineServer.hpp>

struct IGame;
struct IScriptVM;
class CEngineEnv;

class CEngineServer final : public IEngineServer
{
public:
	CEngineServer();
	~CEngineServer();
	
	bool Init(ICoreEnv *apCoreEnv) override;
	void Shutdown() override;
	
	void Frame() override;
private:
	bool InitGame();
	
	std::unique_ptr<CEngineEnv> mpEnv;
	
	ICoreEnv *mpCoreEnv{nullptr};
	IScriptVM *mpGlobalScript{nullptr};
	IGame *mpGame{nullptr};
};