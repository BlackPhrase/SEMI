/// @file
/// @brief command arguments

#pragma once

#include <string>
#include <unordered_map>

//#include "CommonTypes.hpp"
#include "core/ICmdArgs.hpp"

class CCmdArgs final : public ICmdArgs
{
public:
	CCmdArgs(const char *asText);
	CCmdArgs(int argc, char *argv);
	~CCmdArgs();
	
	bool Contains(const char *asName) const override; // TODO: return int?
	
	int GetCount() const override;
	
	const char *GetByName(const char *asName) const override;
	const char *GetByIndex(int anIndex) const override;
	
	const char *ToString() const override;
private:
	std::string msString{""};
	//std::unordered_map<tString, tString> mArgMap;
};