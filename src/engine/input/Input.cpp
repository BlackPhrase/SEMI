/// @file

#include "Input.hpp"
#include "InputEventDispatcher.hpp"

CInput::CInput(const ICoreEnv &apCoreEnv) : mpCoreEnv(apCoreEnv)
{
	mpEventDispatcher = std::make_unique<CInputEventDispatcher>();
	
	//mpCoreEnv->GetUpdater()->AddUpdateable(this);
};

CInput::~CInput() //= default;
{
	//mpCoreEnv->GetUpdater()->RemoveUpdateable(this);
};

void CInput::Update()
{
	// Used for continuous input processing (non-event based)
	
	// TODO: check all key states
	// TODO: if pressed then mark it
	// TODO: if unpressed then unmark it
	
	mpImpl->Update(mvPressed);
	
	// Copy our pressed keys to previously pressed
	for(auto i = 0; i < sizeof(mbPressed); ++i)
		mvOldPressed[i] = mvPressed[i];
};

void CInput::AddEventListener(IInputEventListener *apListener)
{
	mpEventDispatcher->RemoveListener(apListener);
};

void CInput::RemoveEventListener(IInputEventListener *apListener)
{
	mpEventDispatcher->RemoveListener(apListener);
};

bool CInput::IsKeyPressed(KeyCode anKey) const
{
	// Wasn't pressed the previous frame, became pressed
	return !mvOldPressed[anKey] && mvPressed[anKey];
};

bool CInput::IsKeyReleased(KeyCode anKey) const
{
	// Was pressed the previous frame, not anymore
	return mvOldPressed[anKey] && !mvPressed[anKey];
};

bool CInput::IsKeyDown(KeyCode anKey) const
{
	return mvPressed[anKey];
};