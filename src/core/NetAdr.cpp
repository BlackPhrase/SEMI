#include "NetAdr.hpp"

CNetAdr::CNetAdr() = default;
CNetAdr::~CNetAdr() = default;

bool CNetAdr::IsLocal() const
{
	return false; // TODO
};

INetAdr::Type CNetAdr::GetType() const
{
	return INetAdr::Type::Temp;
};