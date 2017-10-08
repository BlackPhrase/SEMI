#pragma once

///
struct IEngineCore
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	enum class Mode : int
	{
		ListenServer = 0, ///<
		DedicatedServer,  ///<
		DedicatedClient   ///<
	};
	
	///
	struct InitParams
	{
		Mode eMode{Mode::ListenServer}; ///<
	};
	
	///
	virtual void Init(const InitParams &aInitParams) = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual void Frame() = 0;
	
	///
	virtual void Stop() = 0;
	
	///
	virtual void SendCmd(const char *asText) = 0;
};

using pfnGetEngineCore = IEngineCore *(*)(int version);