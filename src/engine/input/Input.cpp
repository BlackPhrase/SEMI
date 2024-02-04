/// @file

#include "Input.hpp"
#include "InputEventDispatcher.hpp"
#include "IInputImpl.hpp"

CInput::CInput(const ICoreEnv &apCoreEnv, CInputEventDispatcher &apEventDispatcher, IInputImpl *apImpl)
	: mpCoreEnv(apCoreEnv), mpEventDispatcher(apEventDispatcher), mpImpl(apImpl)
{
	//mpCoreEnv->GetUpdater()->AddUpdateable(this);
};

CInput::~CInput() = default;
//{
	//mpCoreEnv->GetUpdater()->RemoveUpdateable(this);
//};

void CInput::Update()
{
	// Used for continuous input processing (non-event based)
	
	// TODO: check all key states
	// TODO: if pressed then mark it
	// TODO: if unpressed then unmark it
	
	if(mpImpl)
		mpImpl->Update(mvKeyStates);
};

void CInput::AddEventListener(IInputEventListener *apListener)
{
	mpEventDispatcher.get().RemoveListener(apListener);
};

void CInput::RemoveEventListener(IInputEventListener *apListener)
{
	mpEventDispatcher.get().RemoveListener(apListener);
};

void CInput::KeyEvent(KeyCode aeKey, bool abDown)
{
	if(abDown)
		mpEventDispatcher.get().KeyPressed(aeKey);
	else
		mpEventDispatcher.get().KeyReleased(aeKey);
};