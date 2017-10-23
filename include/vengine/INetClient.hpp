#pragma once

struct INetAdr;

struct INetClient
{
	///
	virtual bool Connect(const char *hostname) = 0;
	
	///
	virtual void Disconnect(const char *reason, ...) = 0;
	
	///
	virtual bool IsConnected() const = 0;
	
	///
	virtual INetAdr *GetNetAdr() const = 0;
	
	///
	//virtual IServerInfo *GetServerInfo() const = 0;
};