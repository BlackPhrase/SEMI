/// @file

#pragma once

#include "core/ICoreEnv.hpp"
#include "input/IInputEventListener.hpp"

class CTestInputEventListener final : public IInputEventListener
{
public:
	CTestInputEventListener(ICoreEnv *apCoreEnv) : mpCoreEnv(apCoreEnv){}
	~CTestInputEventListener() = default;
	
	void OnKeyEvent(const SInputEvent &apEvent) override
	{
		switch(apEvent.meDeviceType)
		{
		case IInputDevice::Type::Keyboard:
		case IInputDevice::Type::Gamepad:
			switch(apEvent.meType)
			{
			case SInputEvent::Type::Pressed:
				mpCoreEnv->GetLogger()->Message("Key %d pressed...\n", apEvent.meKey);
				break;
			case SInputEvent::Type::Released:
				mpCoreEnv->GetLogger()->Message("Key %d released...\n", apEvent.meKey);
				break;
			};
		case IInputDevice::Type::Mouse:
			switch(apEvent.meType)
			{
			case SInputEvent::Type::Pressed:
				mpCoreEnv->GetLogger()->Message("Mouse button %d pressed...\n", apEvent.meButton);
				break;
			case SInputEvent::Type::Released:
				mpCoreEnv->GetLogger()->Message("Mouse button %d released...\n", apEvent.meButton);
				break;
			};
		};
	};
private:
	ICoreEnv *mpCoreEnv{nullptr};
};