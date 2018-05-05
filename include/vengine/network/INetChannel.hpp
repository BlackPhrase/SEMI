/// @file
/// @brief network channel interface

#pragma once

struct INetAdr;

struct INetChannel
{
	///
	virtual void SetRate(float afRate) = 0;
	
	///
	virtual float GetRate() const = 0;
	
	///
	virtual INetAdr *GetAdr() const = 0;
};