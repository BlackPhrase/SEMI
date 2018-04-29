/// @file
/// @brief engine core interface

#pragma once

struct IEngineCore
{
	/// Interface version
	static constexpr auto Version{1};
	
	/// Core initialization mode
	enum class Mode : int
	{
		ListenServer = 0, ///< Run as listenserver (client + server)
		DedicatedServer,  ///< Run in dedicated server mode (server-only)
		DedicatedClient   ///< Run in dedicated client mode (client-only)
	};
	
	/// Core initialization preferences
	struct InitParams
	{
		Mode ExecMode{Mode::ListenServer}; ///<
	};
	
	/**
	 * Try to initialize the core
	 *
	 * @param InitParams - initialization preferences
	 * @return true if success
	 */
	virtual bool Init(const InitParams &aInitParams) = 0;
	
	/// Shutdown the core (if initialized)
	virtual void Shutdown() = 0;
	
	/// Run a single frame
	virtual bool Frame() = 0;
	
	///
	virtual void RequestClose() = 0;
};

using pfnGetEngineCore = IEngineCore *(*)(int anVersion);