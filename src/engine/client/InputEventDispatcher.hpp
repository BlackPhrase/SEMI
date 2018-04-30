/// @file

#pragma once

#include <list>

#include "client/IInputEventDispatcher.hpp"

struct IInputEventListener;
using tInputEventListenerList = std::list<IInputEventListener*>;

class CInputEventDispatcher final : public IInputEventDispatcher
{
public:
	CInputEventDispatcher();
	~CInputEventDispatcher();
	
	void AddListener(IInputEventListener *apListener) override;
	void RemoveListener(IInputEventListener *apListener) override;
	
	void KeyPressed(int anKey);
	void KeyReleased(int anKey);
private:
	tInputEventListenerList mlstListeners;
};