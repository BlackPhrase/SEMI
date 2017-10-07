#pragma once

class CNetClient final
{
public:
	CNetClient();
	~CNetClient();
	
	bool Connect(const char *hostname);
	void Disconnect();
	
	bool IsConnected() const;
};