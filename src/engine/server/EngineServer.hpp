/// @file

#pragma once

#include "server/IEngineServer.hpp"

struct IGame;

class CEngineServer final : public IEngineServer
{
public:
	CEngineServer();
	~CEngineServer();
	
	void Init() override;
	void Shutdown() override;
	
	void Frame() override;
private:
	bool InitGame();
	
	IGame *mpGame{nullptr};
};