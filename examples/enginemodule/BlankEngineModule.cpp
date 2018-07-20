/// @file

#include "BlankEngineModule.hpp"

CEngineModule::CEngineModule() = default;
CEngineModule::~CEngineModule() = default;

IFactory *CEngineModule::GetFactory() const
{
	return nullptr; // TODO: &gLocalFactory
};