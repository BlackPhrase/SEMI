#pragma once

#include <vector>

class IClient;
using tClientVec = std::vector<IClient*>;

class CNetServer final
{
public:
	CNetServer();
	~CNetServer();
	
	IClient *GetClientByID(int index) const;
private:
	tClientVec mvClients;
};