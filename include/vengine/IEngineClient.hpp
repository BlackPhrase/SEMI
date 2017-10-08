#pragma once

struct IEngineCore;

struct IEngineClient
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	virtual void Init(IEngineCore *apCore) = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual void Frame() = 0;
};

using pfnGetEngineClient = IEngineClient *(*)(int version);