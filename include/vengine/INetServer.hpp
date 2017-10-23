#pragma once

struct INetClient;

struct INetServer
{
	///
	virtual INetClient *GetClient(int id) const = 0;
	
	///
	virtual int GetClientCount() const = 0;
	
	///
	virtual int GetMaxClients() const = 0;
};