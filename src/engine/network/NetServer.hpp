/// @file

#pragma once

#include <vector>

struct IClient;
using tClientVec = std::vector<IClient*>;

class CNetServer final
{
public:
	CNetServer(int anPort);
	~CNetServer();
	
	void Receive();
	
	IClient *GetClientByID(int index) const {return mvClients.at(index);}
private:
	int FindFreeSlot() const;
	
	tClientVec mvClients;
	
	int svsock{0};
};