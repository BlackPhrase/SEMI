/// @file

#pragma once

#include <chrono>
#include <functional>

class CTimer final
{
public:
	using pfnCallback = std::function<void()>;
	
	CTimer(std::chrono::milliseconds anTimeStep);
	~CTimer();
	
	void Start();
	void Stop();
	
	void SetCallback(pfnCallback afnCallback){mfnCallback = afnCallback;}
	
	void Tick();
	//bool WantUpdate();
	
	void SetTimeStep(std::chrono::milliseconds anTimeStep){mnTimeStep = anTimeStep;}
	std::chrono::milliseconds GetTimeStep() const {return mnTimeStep;}
private:
	void Update();
	
	std::chrono::milliseconds mnTimeStep{0};
	
	pfnCallback mfnCallback{nullptr};
};