/// @file

#include "CmdArgs.hpp"

CCmdArgs::CCmdArgs(const char *asText)
{
	std::stringstream sStream{asText};
	tString sToken{""};
	tStringVec vTokens{};
	
	// Tokenize the string
	
	// TODO
	//tString sArgs{asText};
	
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
		
		if(It[0] == '-' || It[0] == '+')
		{
			sKey = It;
			
			if(++It[0] != '-' && ++It[0] != '+')
				sValue = ++It;
		};
		
		if(!sKey.empty())
			mArgMap.try_emplace(sKey, sValue); // TODO: insert_or_assign
	};
};

CCmdArgs::CCmdArgs(int argc, char **argv)
{
	for(int i = 0; i < argc; ++i)
		mArgMap.try_emplace(argv[i]);
};

CCmdArgs::~CCmdArgs() = default;

int CCmdArgs::Contains(const char *asName) const
{
	auto SearchResult{mArgMap.find(asName)};
	
	if(SearchResult != mArgMap.end())
		return SearchResult - mArgMap.begin(); // std::distance(mArgMap.begin(), SearchResult);
	
	return -1;
};

int CCmdArgs::GetCount() const
{
	return mArgMap.size();
};

const char *CCmdArgs::GetByName(const char *asName) const
{
	auto SearchResult{mArgMap.find(asName)};
	
	if(SearchResult != mArgMap.end())
		return SearchResult->second.c_str();
	
	return "";
};

const char *CCmdArgs::GetByIndex(int anIndex) const
{
	// TODO: check for emptiness?
	
	return mArgMap.at(anIndex).second.c_str();
};

const char *CCmdArgs::ToString() const
{
	return msString.c_str(); // TODO
};