#pragma once

struct IEngineServer
{
	virtual void Init() = 0;
	virtual void Shutdown() = 0;
	
	virtual void Frame() = 0;
};