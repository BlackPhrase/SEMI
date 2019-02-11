/// @file

#include "CommonTypes.hpp"
#include "Input.hpp"

C_EXPORT IInput *GetInput(int anVersion, const ICoreEnv &apCoreEnv)
{
	if(anVersion == IInput::Version)
	{
		static CInput Input(apCoreEnv);
		return &Input;
	};
	
	return nullptr;
};