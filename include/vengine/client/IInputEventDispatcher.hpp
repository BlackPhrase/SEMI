/// @file
/// @brief input event dispatcher interface

#pragma once

struct IInputEventListener;

struct IInputEventDispatcher
{
	///
	virtual void AddListener(IInputEventListener *apListener) = 0;
	
	///
	virtual void RemoveListener(IInputEventListener *apListener) = 0;
};