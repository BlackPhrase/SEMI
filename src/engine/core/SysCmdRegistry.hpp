/*
 * This file is part of V-Engine
 *
 * Copyright 2018, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#pragma once

#include <vector>

#include <CommonTypes.hpp>
#include <core/ISysCmd.hpp>
//#include <core/ISysCmdRegistry.hpp>

using pfnSysCmdCallback = void (*)(const ICmdArgs &aArgs);

class CSysCmd : public ISysCmd
{
public:
	CSysCmd(const tString &asName, pfnSysCmdCallback afnCallback, const char *asDescription = "")
		: msName(asName), mfnCallback(afnCallback), msDesc(asDescription){}
	
	void Exec(const ICmdArgs &aArgs)
	{
		if(mfnCallback)
			mfnCallback(aArgs);
	};
	
	const char *GetName() const {return msName.c_str();}
	const char *GetDesc() const {return msDesc.c_str();}
private:
	tString msName{""};
	tString msDesc{""};
	
	pfnSysCmdCallback mfnCallback{nullptr};
};

using tSysCmdVec = std::vector<CSysCmd*>;

class CSysCmdRegistry final //: public ISysCmdRegistry
{
public:
	CSysCmdRegistry();
	~CSysCmdRegistry();
	
	bool Add(const char *asName, pfnSysCmdCallback afnCallback, const char *asDescription); //override;
	bool Remove(const char *asName); //override;
	
	CSysCmd *Find(const char *asName) const;
private:
	tSysCmdVec mvCmds;
};