/// @file

#pragma once

#include <memory>

//#include "core/IUpdateable.hpp"
#include "input/IInput.hpp"

struct IInputImpl;

class CInput final : /*public IUpdateable,*/ public IInput
{
public:
	CInput(const ICoreEnv &apCoreEnv);
	~CInput();
	
	void Update() override;
	
	void AddEventListener(IInputEventListener *apListener) override;
	void RemoveEventListener(IInputEventListener *apListener) override;
	
	bool IsKeyPressed(KeyCode anKey) const override; // TODO: BecamePressed?
	bool IsKeyReleased(KeyCode anKey) const override; // TODO: BecameReleased?
	
	bool IsKeyDown(KeyCode anKey) const override;
private:
	bool mbPressed[256]{};
	bool mbOldPressed[256]{};
	
	std::unique_ptr<CInputEventDispatcher> mpEventDispatcher;
	
	const ICoreEnv &mpCoreEnv;
	
	IInputImpl *mpImpl{nullptr};
};