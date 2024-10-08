/*
 * This file is part of V-Engine
 *
 * Copyright 2024 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include <cstdio>

#include <iostream>
#include <sstream>

#include <unordered_map>
#include <string_view>
#include <functional>

constexpr auto APP_NAME{"vengprojutil"};
constexpr auto APP_VERSION{"v0.1"};

//using tCmdCallbackFn = std::function<void(int, char**)>;
using tCmdCallbackFn = std::function<void(const std::vector<std::string> &)>;

std::unordered_map<std::string_view, tCmdCallbackFn> gCmdsMap;

void CallbackFn_Help(const std::vector<std::string> &avArgs)
{
	std::cout << "Usage: " << APP_NAME << " [options]" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "\t--help\t\tDisplays this information." << std::endl;
	std::cout << "\t--version\t\tDisplays version information." << std::endl;
	std::cout << "\t-create\t\tCreate a new project." << std::endl;
	std::cout << "\t-open\t\tOpen a project." << std::endl;
};

void CallbackFn_Version(const std::vector<std::string> &avArgs)
{
	std::cout << "V-Engine Project Utility " << APP_VERSION << "\n" << std::endl;
};

void CallbackFn_Create(const std::vector<std::string> &avArgs)
{
	if(avArgs.empty() || avArgs.size() < 2)
	{
		std::cout << "Usage: -create [name] [path]" << std::endl;
		return;
	};
	
	std::cout << "Creating " << avArgs.at(0) << " at " << avArgs.at(1) << std::endl;
};

void CallbackFn_Open(const std::vector<std::string> &avArgs)
{
	if(avArgs.empty() || avArgs.size() < 1)
	{
		std::cout << "Usage: -open [name]" << std::endl;
		return;
	};
	
	std::cout << "Opening " << avArgs.at(0) << std::endl;
};

bool RegisterCmd(std::string_view asCmdName, tCmdCallbackFn afnCmdCallback)
{
	return gCmdsMap.try_emplace(asCmdName, afnCmdCallback).second;
};

void Init()
{
	RegisterCmd("--help", CallbackFn_Help);
	
	//gCmdsMap.try_emplace("-v", CallbackFn_Version);
	RegisterCmd("--version", CallbackFn_Version);
	
	RegisterCmd("-create", CallbackFn_Create);
	RegisterCmd("-open", CallbackFn_Open);
};

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cout << "Usage: " << APP_NAME << " [options]" << std::endl;
		return EXIT_SUCCESS; // TODO: EXIT_FAILURE?
	};
	
	Init();
	
	std::string sCmd{""};
	
	//while(std::cin.peek() != 'q')
	{
		//std::cin >> sCmd;
		
		for(auto i = 0; i < argc; ++i)
		{
			sCmd += argv[i];
			sCmd += " ";
		};
		
		//std::getline(std::cin, sCmd);
		
		std::cout << "Cmd echo: " << sCmd << std::endl;
		
		std::istringstream CmdLineArgs(sCmd);
		
		std::string sFilePath{""};
		std::string sCmdName{""};
		
		CmdLineArgs >> sFilePath >> sCmdName;
		
		std::cout << "Cmd name: " << sCmdName << std::endl;
		
		//std::cout << "Cmd args: ";
		//CmdLineArgs >> std::cout.rdbuf();
		//std::cout << std::endl;
		
		std::vector<std::string> vCmdArgs;
		
		// Skip the whitespace
		CmdLineArgs.get();
		
		for(std::string sArg; std::getline(CmdLineArgs, sArg, ' ');)
		{
			std::cout << "Arg: " << sArg << std::endl;
			vCmdArgs.push_back(std::move(sArg));
		};
		
		if(gCmdsMap.contains(sCmdName))
		{
			//gCmdsMap[sCmdName](0, nullptr);
			gCmdsMap[sCmdName](vCmdArgs);
		}
		else
			std::cout << "Command not found!" << std::endl;
	};
	
	return EXIT_SUCCESS;
};