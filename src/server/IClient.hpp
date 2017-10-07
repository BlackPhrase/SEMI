#pragma once

struct IClient
{
	virtual void Disconnect(const char *reason, ...) = 0;
};