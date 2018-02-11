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
		Mode ExecMode{Mode::ListenServer}; ///<
	};
	
	///
	virtual bool Init(const InitParams &aInitParams) = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual bool Frame() = 0;
	
	///
	virtual void Stop() = 0;
	
	///
	virtual void SendCmd(const char *asText) = 0;
};

using pfnGetEngineCore = IEngineCore *(*)(int anVersion);