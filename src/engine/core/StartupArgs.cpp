/*
 * This file is part of V-Engine
 *
 * Copyright 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include "StartupArgs.hpp"

CStartupArgs::CStartupArgs(const char *asArgs)
{
	msArgs = asArgs;
	
	std::stringstream sStream{asArgs};
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
	
	tString sKey{""};
	tString sValue{""};
	
	for(auto It : vTokens)
	{
		sKey = "";
		sValue = "";
		
		// Check if arg is a key
		if(It[0] == '-' || It[0] == '+')
		{
			sKey = It;
			
			// Check if value is not another key
			if(++It[0] != '-' && ++It[0] != '+')
				sValue = It++;
		};
		
		if(!sKey.empty())
			mArgMap.try_emplace(sKey, sValue); // TODO: insert_or_assign
	};
};

CStartupArgs::CStartupArgs(int anArgs, char **asvArg)
{
	char *sKey{nullptr};
	char *sValue{nullptr};
	
	msString = "";
	
	for(int i = 0; i < anArgs; ++i)
	{
		sKey = asvArg[i];
		msArgs += asvArg[i];
		
		++i;
		
		// Check for key-value pair
		if(sKey[0] == '-' || sKey[0] == '+')
		{
			sValue = asvArg[i];
			
			msArgs += " ";
			msArgs += asvArg[i];
			
			++i;
			
			if(i < anArgs)
				msArgs += " ";
		};
		
		mArgMap.try_emplace(sKey, sValue);
	};
};

bool CStartupArgs::Contains(const char *asKey) const
{
	auto SearchResult{mArgMap.find(asKey)};
	
	if(SearchResult != mArgMap.end())
		//return SearchResult - mArgMap.begin(); // std::distance(mArgMap.begin(), SearchResult);
		return true;
	
	//return -1;
	return false;
};

int CStartupArgs::GetCount() const
{
	return mArgMap.size();
};

const char *CStartupArgs::Get(const char *asKey) const
{
	auto SearchResult{mArgMap.find(asKey)};
	
	if(SearchResult != mArgMap.end())
		return SearchResult->second.c_str();
	
	return "";
};

const char *CStartupArgs::ToString() const
{
	return msArgs.c_str();
};