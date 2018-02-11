#pragma once

#include "vengine/IEngineCore.hpp"

struct IEngineExecMode
{
	///
	virtual void Init(IEngineCore *apCore){}
	
	///
	virtual void Shutdown(){}
	
	///
	virtual void FrameBegin(){}
	
	///
	virtual void FrameEnd(){}
	
	///
	virtual void HandleInput(){}
	
	///
	virtual void Frame(float afTimeStep){}
	
	///
	virtual void Render(){}
};