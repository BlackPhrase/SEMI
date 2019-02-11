/// @file

#include "InputEventDispatcher.hpp"
#include "input/IInputEventListener.hpp"

CInputEventDispatcher::CInputEventDispatcher() = default;
CInputEventDispatcher::~CInputEventDispatcher() = default;

void CInputEventDispatcher::AddListener(IInputEventListener *apListener)
{
	mlstListeners.push_back(apListener);
};

void CInputEventDispatcher::RemoveListener(IInputEventListener *apListener)
{
	mlstListeners.remove(apListener);
};

void CInputEventDispatcher::KeyPressed(int anKey)
{
	for(auto It : mlstListeners)
		It->OnKeyPressed(anKey);
};

void CInputEventDispatcher::KeyReleased(int anKey)
{
	for(auto It : mlstListeners)
		It->OnKeyReleased(anKey);
};