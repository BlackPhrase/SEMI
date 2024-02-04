/// @file

#pragma once

#include "core/IConfig.hpp"

using dictionary = struct _dictionary_;

class CConfig final : public IConfig
{
public:
	CConfig();
	CConfig(const char *asPath);
	~CConfig();
	
	bool LoadFromFile(const char *asPath);
	bool SaveToFile(const char *asPath);
	
	void SetString(const char *asKey, const char *asValue) override;
	const char *GetString(const char *asKey) const override;
private:
	dictionary *mpDict{nullptr};
};