/// @file

#pragma once

#include "IEngineModule.hpp"

class CEngineModule final : public IEngineModule
{
public:
	CEngineModule();
	~CEngineModule();
	
	IFactory *GetFactory() const override;
};