#pragma once

struct IEngineCore;
struct INetClient;

struct IEngineClient
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	virtual void Init(IEngineCore *apCore) = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	//virtual void HandleInput() = 0;
	
	///
	virtual void Frame() = 0;
	
	///
	//virtual void Render() = 0;
	
	///
	virtual INetClient *GetLocalClient() const = 0;
};

using pfnGetEngineClient = IEngineClient *(*)(int version);