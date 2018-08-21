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
	
	/// Use this to load a module using its name
	/// @return pointer to the loaded module or nullptr if failed
	SModuleHandle *LoadModule(const std::string &asName);
	
	/// Unload a module by its handle
	void UnloadModule(SModuleHandle *apModule);
	
	/// Get module by its index
	SModuleHandle *GetByIndex(int anID) const {return mvModules.at(anID);}
	
	/// Get module by its name
	SModuleHandle *GetByName(const std::string &asName) const;
private:
	tModuleHandleVec mvModules;
	
	CModuleLoader *mpLoader{nullptr};
};