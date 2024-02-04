/*
 * This file is part of V-Engine
 *
 * Copyright 2018-2019, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#pragma once

#include <list>

#include "core/ILogger.hpp"

using tLogSinkList = std::list<ILogSink*>;

class CLogger final : public ILogger
{
public:
	CLogger();
	~CLogger();
	
	void AddSink(ILogSink *apSink) override;
	void RemoveSink(ILogSink *apSink) override;
	
	void Message(const char *asMsg, ...) override;
private:
	tLogSinkList mlstSinks;
};