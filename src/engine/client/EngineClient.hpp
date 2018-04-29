/// @file

#pragma once

#include <memory>

#include "client/IEngineClient.hpp"

class CRenderWindowGLFW;

class CEngineClient final : public IEngineClient
{
public:
	CEngineClient();
	~CEngineClient();
	
	bool Init(ICoreEnv *apCoreEnv) override;
	void Shutdown() override;
	
	void Frame() override;
	
	INetClient *GetLocalClient() const override {return nullptr;}
private:
	std::unique_ptr<CRenderWindowGLFW> mpMainWindow;
	
	ICoreEnv *mpCoreEnv{nullptr};
};