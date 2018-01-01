#pragma once

#include "vengine/INetAdr.hpp"

class CNetAdr final : public INetAdr
{
public:
	CNetAdr();
	~CNetAdr();
	
	bool IsLocal() const override;
	
	INetAdr::Type GetType() const override;
};