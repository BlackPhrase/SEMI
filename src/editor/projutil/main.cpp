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
#include <fstream>
#include <sstream>

#include <map>
#include <unordered_map>
#include <string_view>
#include <functional>
#include <filesystem>

constexpr auto APP_NAME{"vengprojutil"};
constexpr auto APP_VERSION{"0.1.1"};

constexpr auto DEFAULT_PROJECT_PATH{"./projects/"};
constexpr auto DEFAULT_PROJECT_EXT{".vengproj"};

//using tCmdCallbackFn = std::function<void(int, char**)>;
using tCmdCallbackFn = std::function<void(const std::vector<std::string> &)>;

std::unordered_map<std::string_view, tCmdCallbackFn> gCmdsMap;
std::map<std::string_view, std::string_view> gCmdDescsMap;

void CallbackFn_Help(const std::vector<std::string> &avArgs)
{
	std::cout << "Usage: " << APP_NAME << " [options]" << std::endl;
	std::cout << "Options:" << std::endl;
	
	for(const auto &It : gCmdDescsMap)
		std::cout << "\t" << It.first << "\t\t" << It.second << std::endl;
};

void CallbackFn_Version(const std::vector<std::string> &avArgs)
{
	std::cout << "V-Engine Project Utility v" << APP_VERSION << std::endl;
};

void CallbackFn_Create(const std::vector<std::string> &avArgs)
{
	if(avArgs.empty() || avArgs.size() > 2)
	{
		std::cout << "Usage: -create <name> [path]" << std::endl;
		return;
	};
	
	std::string sProjectPath{DEFAULT_PROJECT_PATH};
	std::string sProjectName{avArgs.at(0)};
	
	if(avArgs.size() > 1)
		sProjectPath = avArgs[1];
	
	std::filesystem::path ProjectPath{sProjectPath};
	
	auto ProjectFullPath{ProjectPath / sProjectName / (sProjectName + DEFAULT_PROJECT_EXT)};
	
	// Make sure the project is not already exists
	if(std::filesystem::exists(ProjectFullPath))
	{
		std::cout << "Error: " << "The project with the same name is already present!" << std::endl;
		return;
	};
	
	std::cout << "Creating " << sProjectName << " at " << sProjectPath << std::endl;
	
	{
		std::filesystem::create_directories(ProjectFullPath.parent_path());
		
		std::ofstream ProjectFile(ProjectFullPath);
		ProjectFile << "Hi there!\n";
		ProjectFile.close();
	};
};

void CallbackFn_Open(const std::vector<std::string> &avArgs)
{
	if(avArgs.empty() || avArgs.size() < 1)
	{
		std::cout << "Usage: -open <name>" << std::endl;
		return;
	};
	
	std::string sProjectName{avArgs.at(0)};
	
	std::filesystem::directory_entry ProjectPath(std::filesystem::path(DEFAULT_PROJECT_PATH) / sProjectName / (sProjectName + DEFAULT_PROJECT_EXT));
	
	if(!ProjectPath.exists())
	{
		std::cout << "Error: " << "Cannot find the specified project!" << std::endl;
		return;
	};
	
	std::cout << "Opening \"" << sProjectName << "\"..." << std::endl;
	std::system((std::string("VEngineEditor ") + sProjectName).c_str());
};

void CallbackFn_ListProjects(const std::vector<std::string> &avArgs)
{
	std::cout << "Projects:" << std::endl;
	
	for(const auto &It : std::filesystem::directory_iterator(DEFAULT_PROJECT_PATH))
		if(It.is_directory() && std::filesystem::exists(It.path() / (It.path().stem().string() + DEFAULT_PROJECT_EXT)))
			std::cout << It << std::endl;
};

bool RegisterCmd(std::string_view asCmdName, tCmdCallbackFn afnCmdCallback, std::string_view asCmdDesc)
{
	if(gCmdsMap.try_emplace(asCmdName, afnCmdCallback).second)
	{
		gCmdDescsMap.try_emplace(asCmdName, asCmdDesc);
		return true;
	};
	
	return false;
};

void Init()
{
	RegisterCmd("--help", CallbackFn_Help, "Displays this information.");
	
	//gCmdsMap.try_emplace("-v", CallbackFn_Version, "");
	RegisterCmd("--version", CallbackFn_Version, "Displays version information.");
	
	RegisterCmd("-create", CallbackFn_Create, "Create a new project.");
	RegisterCmd("-open", CallbackFn_Open, "Open a project.");
	
	RegisterCmd("-ls", CallbackFn_ListProjects, "Displays available projects.");
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