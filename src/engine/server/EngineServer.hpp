/// @file

#pragma once

#include "server/IEngineServer.hpp"

struct IGame;
class CServerEnv;

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
	
	CServerEnv *mpServerEnv{nullptr};
	IGame *mpGame{nullptr};
};