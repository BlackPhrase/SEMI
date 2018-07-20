/// @file
/// @brief internal log sink (temp?)

#pragma once

#include <iostream>

#include "core/ILogger.hpp"

class CLogSinkInternal final : public ILogSink
{
public:
	CLogSinkInternal() = default;
	~CLogSinkInternal() = default;
	
	void OnMessage(const char *asMsg) override
	{
		std::cout << asMsg << std::endl;
	};
};