/// @file

#pragma once

#include "IClient.hpp"

struct INetChannel;

class CClient final : public IClient
{
public:
	CClient();
	~CClient();
	
	void Disconnect(const char *asReason, ...) override;
	
	bool IsConnected() const override {return mbConnected;}
private:
	INetChannel *mpChannel{nullptr};
	
	bool mbConnected{false};
};