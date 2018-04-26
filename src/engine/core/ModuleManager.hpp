/// @file
/// @brief module manager - loads and stores loaded modules instances inside

#pragma once

#include <vector>
#include <string>

class CModuleLoader;

struct SModuleHandle;
using tModuleHandleVec = std::vector<SModuleHandle*>;

class CModuleManager final // CModuleContainer?
{
public:
	CModuleManager() = default;
	~CModuleManager() = default;
	
	SModuleHandle *LoadModule(const std::string &asName);
	void UnloadModule(SModuleHandle *apModule);
	
	SModuleHandle *GetModule(int anID) const {return mvModules.at(anID);}
	SModuleHandle *GetModule(const std::string &asName) const;
private:
	tModuleHandleVec mvModules;
	
	CModuleLoader *mpLoader{nullptr};
};