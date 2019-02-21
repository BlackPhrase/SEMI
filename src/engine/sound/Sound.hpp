/// @file

#pragma once

#include "sound/ISound.hpp"

class CSound final : public ISound
{
public:
	CSound(const ICoreEnv &apCoreEnv);
	~CSound();
	
	bool Init(int anFrequency, int anChannels, int anSampleSize) override;
	void Shutdown() override;
	
	void Update() override;
private:
	const ICoreEnv &mpCoreEnv;
};