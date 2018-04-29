/// @file

#pragma once

struct ICoreEnv;

struct IEngineExecMode
{
	///
	virtual void Init(ICoreEnv *apCoreEnv){}
	
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