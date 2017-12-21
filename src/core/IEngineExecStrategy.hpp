#pragma once

#include "vengine/IEngineCore.hpp"

struct IEngineExecStrategy
{
	///
	virtual void Init(IEngineCore *apCore) = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual void Frame() = 0;
};