/// @file
/// @brief input event listener interface

#pragma once

struct IInputEventListener
{
	///
	virtual void OnKeyPressed(int anKey) = 0;
	
	///
	virtual void OnKeyReleased(int anKey) = 0;
};