#pragma once

#include <vector>
#include <string>

class CModuleLoader;

using tModuleHandleVec = std::vector<TModuleHandle*>;

class CModuleManager final
{
public:
	CModuleManager() = default;
	~CModuleManager() = default;
	
	SModuleHandle *LoadModule(const std::string &name);
	void UnloadModule(TModuleHandle *apModule);
	
	SModuleHandle *GetModule(int anID) const;
	SModuleHandle *GetModule(const std::string &name) const;
private:
	tModuleHandleVec mvModules;
	
	CModuleLoader *mpModuleLoader{nullptr};
};