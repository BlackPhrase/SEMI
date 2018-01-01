#pragma once

class CTimer final
{
public:
	CTimer();
	~CTimer();
	
	void Start();
	
	float GetTimeStep() const;
private:
};