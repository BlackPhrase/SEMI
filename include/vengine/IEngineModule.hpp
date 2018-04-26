/// @file

#pragma once

/// Main module export
using pfnModuleMain = void (*)();

struct IFactory
{
	///
	virtual void *GetInterface(void *type, int version) const = 0;
	
	/// Templated version of the above method
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

class CBaseEngineModule : public IEngineModule
{
public:
	CBaseEngineModule() = default;
	~CBaseEngineModule() = default;
	
	IFactory *GetFactory() const override
	{
		return nullptr;
	};
};