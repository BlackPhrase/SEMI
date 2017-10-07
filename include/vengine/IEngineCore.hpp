#pragma once

///
struct IEngineCore
{
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
};