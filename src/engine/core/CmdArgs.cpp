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

#include <sstream>

#include "CmdArgs.hpp"

CCmdArgs::CCmdArgs(const char *asArgs)
{
	msArgs = asArgs;
	
	std::istringstream sStream{asArgs};
	tString sToken{""};
	tStringVec vTokens{};
	
	// Tokenize the string
	
	// TODO
	//tString sArgs{asArgs};
	
	//regex reg("\\s+");
	
	//sregex_token_iterator iter(sArgs.begin(), sArgs.end(), reg, -1);
	//sregex_token_iterator end;
	
	//tStringVec vTokens{iter, end};
	//
	
	while(getline(sStream, sToken, ' '))
		vTokens.push_back(sToken);
	
	// Now parse it
	// * Each key starts either with '-' or '+'
	// * Each value is either a string or number
	//
	// "blah.exe -blah +blah =crashit ;boom #3-1 -arg 20 +arg 30"
	// blah.exe = [0]
	
	mvArgs = vTokens;
};

CCmdArgs::CCmdArgs(int anArgs, char **asvArg)
{
	msArgs = "";
	
	for(int i = 0; i < anArgs; ++i)
	{
		mvArgs.emplace_back(asvArg[i]);
		
		msArgs += asvArg[i];
		
		if((i + 1) < anArgs)
			msArgs += " ";
	};
};

CCmdArgs::~CCmdArgs() = default;

int CCmdArgs::GetCount() const
{
	return mvArgs.size();
};

const char *CCmdArgs::GetAt(int anIndex) const
{
	if(anIndex < 0 || anIndex >= GetCount())
		return nullptr; // TODO: return "";?
	
	return mvArgs[anIndex].c_str();
};

const char *CCmdArgs::ToString() const
{
	return msArgs.c_str();
};