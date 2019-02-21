/// @file

#pragma once

#include <memory>

#include "client/IEngineClient.hpp"

struct IRenderWindow;
struct IInput;
struct ISound;
struct IClientGame;
class CEngineEnv;
class CInputEventDispatcher;

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
	bool InitInput();
	bool InitSound();
	bool InitGame();
	
	std::unique_ptr<CEngineEnv> mpEnv;
	std::unique_ptr<CInputEventDispatcher> mpInputEventDispatcher;
	std::unique_ptr<IRenderWindow> mpMainWindow;
	
	ICoreEnv *mpCoreEnv{nullptr};
	IInput *mpInput{nullptr};
	ISound *mpSound{nullptr};
	IClientGame *mpGame{nullptr};
};