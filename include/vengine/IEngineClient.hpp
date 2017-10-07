#pragma once

struct IEngineClient
{
	virtual void Init() = 0;
	virtual void Shutdown() = 0;
	
	virtual void Frame() = 0;
};