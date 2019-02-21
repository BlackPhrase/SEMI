/// @file

#include "Sound.hpp"

CSound::CSound(const ICoreEnv &apCoreEnv) : mpCoreEnv(apCoreEnv){}

CSound::~CSound() = default;

bool CSound::Init(int anFrequency, int anChannels, int anSampleSize)
{
	// TODO
	return true;
};

void CSound::Shutdown()
{
	// TODO
};

void CSound::Update()
{
	// TODO
};