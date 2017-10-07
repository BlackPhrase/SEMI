#pragma once

#include "vengine/IEngineServer.hpp"

class CEngineServer final : public IEngineServer
{
public:
	CEngineServer();
	~CEngineServer();
	
	void Init() override;
	void Shutdown() override;
	
	void Frame() override;
};