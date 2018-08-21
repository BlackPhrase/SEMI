/// @file

#pragma once

struct INetworkImpl
{
	virtual bool Init() = 0;
	virtual void Shutdown() = 0;
};