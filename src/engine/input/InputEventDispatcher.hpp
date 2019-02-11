/// @file

#pragma once

#include <list>

struct IInputEventListener;
using tInputEventListenerList = std::list<IInputEventListener*>;

class CInputEventDispatcher final : public IInputEventDispatcher
{
public:
	CInputEventDispatcher();
	~CInputEventDispatcher();
	
	void AddListener(IInputEventListener *apListener);
	void RemoveListener(IInputEventListener *apListener);
	
	void KeyPressed(int anKey);
	void KeyReleased(int anKey);
private:
	tInputEventListenerList mlstListeners;
};