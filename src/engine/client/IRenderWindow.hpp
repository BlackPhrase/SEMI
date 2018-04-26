/// @file
/// @brief render window interface

#pragma once

struct IRenderWindow
{
	///
	virtual bool Init(int width, int height, const char *title) = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual void Update() = 0;
	
	///
	virtual void SetSize(int width, int height) = 0;
	
	///
	virtual void SetPos(int x, int y) = 0;
	
	///
	virtual void SetTitle(const char *title) = 0;
	
	///
	virtual const char *GetTitle() const = 0;
	
	///
	virtual bool WantClose() const = 0;
};