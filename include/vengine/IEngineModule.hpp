#pragma once

struct IFactory
{
	///
	virtual void *GetInterface(int version) const = 0;
	
	///
	template<typename T>
	T *GetInterface(int version) const
	{
		return static_cast<T*>(GetInterface(version));
	};
};

struct IEngineModule
{
	///
	virtual IFactory *GetFactory() const = 0;
};