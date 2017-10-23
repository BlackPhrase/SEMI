#pragma once

#include <memory>
#include "vengine/IEngineClient.hpp"

class CRenderWindowGLFW;

class CEngineClient final : public IEngineClient
{
public:
	CEngineClient();
	~CEngineClient();
	
	void Init(IEngineCore *apCore) override;
	void Shutdown() override;
	
	void Frame() override;
	
	INetClient *GetLocaClient() override;
private:
	std::unique_ptr<CRenderWindowGLFW> mpMainWindow;
};