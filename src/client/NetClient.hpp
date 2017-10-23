#pragma once

#include "vengine/INetClient.hpp"

class CNetClient final : public INetAdr
{
public:
	CNetClient();
	~CNetClient();
	
	bool Connect(const char *hostname) override;
	void Disconnect(const char *reason, ...) override;
	
	bool IsConnected() const override;
	
	INetAdr *GetNetAdr() const override {return mpAdr;}
private:
	INetAdr *mpAdr{nullptr};
	
	bool mbConnected{false};
};