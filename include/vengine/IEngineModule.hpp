#pragma once

struct IFactory
{
	///
	virtual void *GetInterface(void *type, int version) const = 0;
	
	///
	template<typename T>
	T *GetInterface(int version) const
	{
		return static_cast<T*>(GetInterface(T, version));
	};
};

struct IEngineModule
{
	///
	virtual IFactory *GetFactory() const = 0;
};