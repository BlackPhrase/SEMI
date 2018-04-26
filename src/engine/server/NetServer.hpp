/// @file

#pragma once

#include <vector>

struct IClient;
using tClientVec = std::vector<IClient*>;

class CNetServer final
{
public:
	CNetServer();
	~CNetServer();
	
	IClient *GetClientByID(int index) const;
private:
	int FindFreeSlot() const;
	
	tClientVec mvClients;
};