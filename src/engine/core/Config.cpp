/// @file

#include <iniparser.h>

#include "Config.hpp"

CConfig::CConfig() = default;

CConfig::CConfig(const char *asPath)
{
	//if(!mpDict)
		//throw std::runtime_error("Can't load config file \"" + asPath + "\"!");
	
	LoadFromFile(asPath); // TODO
};

CConfig::~CConfig()
{
	if(mpDict)
		iniparser_freedict(mpDict);
};

bool CConfig::LoadFromFile(const char *asPath)
{
	if(mpDict)
		iniparser_freedict(mpDict);
	
	mpDict = iniparser_load(asPath);
	
	if(!mpDict)
		return false;
	
	return true;
};

bool CConfig::SaveToFile(const char *asPath)
{
	auto pFile{fopen(asPath, "w")};
	
	if(!pFile)
		return false;
	
	iniparser_dump_ini(mpDict, pFile);
	fclose(pFile);
	
	return true;
};

void CConfig::SetString(const char *asKey, const char *asValue)
{
	iniparser_set(mpDict, asKey, asValue);
};

const char *CConfig::GetString(const char *asKey) const
{
	return iniparser_getstring(mpDict, asKey, "");
};