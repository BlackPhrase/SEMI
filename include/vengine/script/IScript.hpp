/// @file
/// @brief scripting module interface

#pragma once

struct IScript
{
	/// Interface version
	static constexpr auto Version{1};
	
	///
	virtual bool Init() = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual void Update(float afTimeStep) = 0;
	
	///
	virtual void CallFunc(const char *asName) = 0;
};

using pfnGetScript = IScript *(*)(int anVersion);