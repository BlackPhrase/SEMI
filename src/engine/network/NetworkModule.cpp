/*
 * This file is part of V-Engine
 *
 * Copyright 2018-2019, 2024 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#include <memory>

#include <CommonTypes.hpp>
#include <BaseEngineModule.hpp>

#include "Network.hpp"

#ifdef _WIN32
#	include "win/NetworkWinSock2.hpp"
#endif

class CNetworkModule : public CBaseEngineModule
{
public:
	CNetworkModule(const ICoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	
	bool OnLoad() override
	{
		RegisterInterface("VEngineNetwork", [=, this](int anVersion) -> void* {
			if(anVersion == INetwork::Version)
			{
			#ifdef _WIN32
				static CNetworkWinSock2 NetworkImpl;
			#else
				// TODO
			#endif

				mpNetwork.reset(new CNetwork(mCoreEnv, &NetworkImpl));
				return mpNetwork.get();
			};
			
			return nullptr;
		});
		
		return true;
	};
	
	bool OnUnload() override
	{
		mpNetwork.reset(nullptr);
		
		return true;
	};
private:
	std::unique_ptr<CNetwork> mpNetwork;
	
	const ICoreEnv &mCoreEnv;
};

C_EXPORT IEngineModule *VEngineModuleMain(const ICoreEnv &aCoreEnv)
{
	static CNetworkModule NetworkModule(aCoreEnv);
	return &NetworkModule;
};