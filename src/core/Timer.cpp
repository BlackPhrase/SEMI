#include <cstdio>
#include "Timer.hpp"

CTimer::CTimer(std::chrono::milliseconds anTimeStep) //= default;
{
	SetTimeStep(anTimeStep);
};

CTimer::~CTimer() = default;

void CTimer::Start()
{
};

void CTimer::Stop()
{
};

void CTimer::Tick() // WantUpdate
{
	static auto OldTime{std::chrono::high_resolution_clock::now()};
	auto CurTime{std::chrono::high_resolution_clock::now()};
	auto DeltaTime{std::chrono::duration_cast<std::chrono::milliseconds>(CurTime - OldTime)};
	
	printf("CTimer::Tick (delta: %d / timestep: %d)\n", DeltaTime.count(), mnTimeStep.count());
	if(DeltaTime >= mnTimeStep)
		Update();
	
	OldTime = std::chrono::high_resolution_clock::now();
};

void CTimer::Update()
{
	printf("CTimer::Update\n");
	if(mfnCallback)
		mfnCallback();
};