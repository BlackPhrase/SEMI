#pragma once

struct IEngineServer
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	virtual void Init() = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual void Frame() = 0;
};

using pfnGetEngineServer = IEngineServer *(*)(int version);