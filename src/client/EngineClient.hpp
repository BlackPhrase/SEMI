#pragma once

#include "vengine/IEngineClient.hpp"

class CEngineClient final : public IEngineClient
{
public:
	CEngineClient();
	~CEngineClient();
	
	void Init() override;
	void Shutdown() override;
	
	void Frame() override;
};