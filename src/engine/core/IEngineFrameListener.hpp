/// @file

#pragma once

struct IEngineFrameListener
{
	virtual void PreFrame() = 0;
	virtual void PostFrame() = 0;
	
	virtual void Frame(float afTimeStep) = 0;
};