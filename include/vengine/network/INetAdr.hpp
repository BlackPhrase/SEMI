#pragma once

struct INetAdr
{
	virtual bool IsLocal() const = 0;
	
	enum class Type : int
	{
		Temp
		// TODO
	};
	
	virtual Type GetType() const = 0;
protected:
	virtual ~INetAdr() = default;
};