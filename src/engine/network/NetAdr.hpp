/// @file

#pragma once

#include "network/INetAdr.hpp"

class CNetAdr final : public INetAdr
{
public:
	CNetAdr(int anPort) : mnPort(anPort){}
	~CNetAdr() = default;
	
	bool IsLocal() const override {return false;} // TODO
	INetAdr::Type GetType() const override {return INetAdr::Type::Temp;} // TODO
	int GetPort() const override {return mnPort;}
private:
	int mnPort{0};
};